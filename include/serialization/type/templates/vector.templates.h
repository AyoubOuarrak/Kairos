/**
*   << operator overloading
*/
template <class vector_type>
void VectorSD::add(const std::vector<vector_type>& item) {
    if(Archive::isInOpen())
        Archive::closeInStream();

    if(!Archive::isOutOpen())
        Archive::openOutStream(std::ios::out | std::ios::app);

    for(int i = 0; i < item.size(); ++i) {
        Archive::outStream << item[i];
        Archive::outStream << " ";
    }
} 

/**
*   >> operator overloading
*/
template <class vector_type>
std::vector<vector_type> VectorSD::get() { 
    if(Archive::isOutOpen())
        Archive::closeOutStream();

    if(!Archive::isInOpen())
        Archive::openInStream(std::ios::in);

    std::vector<vector_type> item;
    vector_type el;

    for(; Archive::inStream >> el; ) 
        item.push_back(el);
        
}