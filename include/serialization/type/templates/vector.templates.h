
 /**
 *  Save vector in the archive (text archive by default)
 */
template <class vector_type>
void Vector::put(const std::vector<vector_type>& src) {
    for(auto it = src.begin(); it != src.end(); ++it)
        archive->put(*it);
}

/** 
*   Get the vector from archive (text archive by default)
*/
template <class vector_type>
void Vector::get(std::vector<vector_type>& dest) {
    std::vector<vector_type> restore_vec;
    vector_type value;

    while(archive >> value) {
        restore_vec.push_back(value);
    }
}

