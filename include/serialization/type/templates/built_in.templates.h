
/**
*   Default constructor
*/
BuiltIn::BuiltIn() {
    archive = new TextArchive();
}

BuiltIn::BuiltIn(Archive* _archive) {
    archive = _archive;
}
/**
*   Copy constructor
*/
BuiltIn::BuiltIn(const BuiltIn& built_in) {

}

/**
*   Default dtor
*/
BuiltIn::~BuiltIn() {

}

/**
*   Assignment operator
*/
Archive BuiltIn::operator=(const BuiltIn&) {

}

/**
*   Save a built-in type in the vector
*/
template <class T>
void BuiltIn::put(const T& src) {
    archive->put(src);
}

/**
*   Get a built--in type from the vector
*/
template <class T>
void BuiltIn::get(T& src) {
    archive->get(src);
}

