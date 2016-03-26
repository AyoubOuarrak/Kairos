
/**
*   Save a built-in type in the vector
*/
template <class T>
void BuiltIn::put(T& src) {
    if(dynamic_cast<archive::BinaryArchive*>(archive)) {
        archive->put(reinterpret_cast<char*>(&src), sizeof(T));
    }
    else
        archive->put(src);
}

/**
*   Get a built--in type from the vector
*/
template <class T>
void BuiltIn::get(T& dst) {
    if(dynamic_cast<archive::BinaryArchive*>(archive)) {
        archive->get(reinterpret_cast<char*>(&dst), sizeof(T));
    }
    else
        archive->get(dst);
}

