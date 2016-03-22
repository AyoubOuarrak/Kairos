
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

