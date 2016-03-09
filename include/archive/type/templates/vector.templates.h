/**
*   Default constructor
*/
template <class type, class vector_type = std::vector<type> >
VectorArchive<vector_type>::VectorArchive() : Archive() {

}

/**
*   << operator overloading
*/
template <class type, class vector_type = std::vector<type> >
VectorArchive<vector_type>& 
VectorArchive<vector_type>::operator<<(const vector_type& item) {
    if(io_archive::isInOpen())
        io_archive::closeInStream();

    if(!io_archive::isOutOpen())
        io_archive::openOutStream(std::ios::out | std::ios::app);

    for(int i = 0; i < item.size(); ++i) {
        io_archive::outStream << item[i];
        io_archive::outStream << " ";
    }
    return *this;
} 

/**
*   >> operator overloading
*/
template <class type, class vector_type = std::vector<type> >
VectorArchive<vector_type>& 
VectorArchive<vector_type>::operator>>(vector_type& item) { 
    if(io_archive::isOutOpen())
        io_archive::closeOutStream();

    if(!io_archive::isInOpen())
        io_archive::openInStream(std::ios::in);

    type el;
    for(int i = 0; io_archive::inStream >> el; ++i) 
        item[i] = el;
        
    return *this;
}