
/**
*   Default constructor
*/
template <class vector_type, class archive_type = TextArchive>
Vector::Vector() : Archive() {

}

/**
*   copy operator
*/
template <class vector_type, class archive_type = TextArchive>
Vector::Vector(const Vector& varchive) {
    
}

/**
*   Assignment operator overloading
*/
template <class vector_type, class archive_type = TextArchive>
Archive Vector::operator=(const Vector& varchive) {

}

 /** 
 *  Save vector in the archive (text archive by default)
 */
template <class vector_type, class archive_type = TextArchive>
void Vector::put(const std::vector<vector_type>& src) {

    std::vector<vector_type>::const_iterator vec;

    for(auto it = vec.begin(); it != vec.end(); ++it)
        archive_type.put(*it);
}

/** 
*   Get the vector from archive (text archive by default)
*/
template <class vector_type, class archive_type = TextArchive>
void Vector::get(std::vector<vector_type>& dest) {
    std::vector<vector_type> restore_vec;
    vector_type value;

    while(archive_type >> value) {
        restore_vec.push_back(value);
    }
}

