/**
*   Default constructor
*/
template <class vector_type>
VectorArchive<vector_type>::VectorArchive() : Archive<std::vector<vector_type> >() {

}

/**
*   copy operator
*/
template <class vector_type>
VectorArchive<vector_type>::VectorArchive(const VectorArchive& varchive) {
    
}

/**
*   << operator overloading
*/
template <class vector_type>
VectorArchive<vector_type>& 
VectorArchive<vector_type>::operator<<(const std::vector<vector_type>& item) {
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
template <class vector_type>
VectorArchive<vector_type>& 
VectorArchive<vector_type>::operator>>(std::vector<vector_type>& item) { 
    if(io_archive::isOutOpen())
        io_archive::closeOutStream();

    if(!io_archive::isInOpen())
        io_archive::openInStream(std::ios::in);

    vector_type el;
    for(; io_archive::inStream >> el; ) 
        item.push_back(el);
        
    return *this;
}