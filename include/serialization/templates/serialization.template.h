
/**
*   Restore a serializable object
*/
template <class ClassType>
std::map<std::string, ClassType*> Serialization::restore() {
    serializationIndexOut.close();
    serializationIndexIn.close();
    serializationIndexIn.open("serialization.index", std::ios::in);

    std::string className;
    std::string classSerializationFormat;
    std::string classSerializationFile;
    std::map<std::string, ClassType*> serializedObjects;
    int counter = 1;

    /** iterate over the serialization index */
    while(serializationIndexIn >> className >> classSerializationFormat >> classSerializationFile) {
        /** if the classname is the same the template type */
        if(utils::is_same<ClassType>(className)) {
            /** create a new empty object, get the file name of the archive and start to load data */
            ClassType* object = new ClassType();

            try {
                if (classSerializationFormat == Serialization::TEXT) {
                    TextArchive archive(classSerializationFile);
                    object->deserialize(archive);
                }

                if (classSerializationFormat == Serialization::BINARY) {
                    BinaryArchive archive(classSerializationFile);
                    object->deserialize(archive);
                }

                serializedObjects.insert(std::pair<std::string, ClassType*>(className + std::to_string(counter++), object));
                registerType(object, classSerializationFormat);
                //std::cout <<

            } catch (std::out_of_range exp) {
                std::cout << exp.what() << std::endl;
                throw new SerializationException("errors trying to deserialize " + className);

            } catch (SerializationException* exp) {
                throw exp;
            }
        }
    }

    return serializedObjects;
}