
/**
*   Default constructor 
*/
template <class item_type>
Archive<item_type>::Archive() : input_archive(), output_archive(), archivePath(".") {
 
}

/**
*   Second constructor 
*/
template <class item_type>
Archive<item_type>::Archive(std::string path) : input_archive(), output_archive() {
    archivePath = path;
}

/**
*   Default distructor 
*/
template <class item_type>
Archive<item_type>::~Archive() {

}

/**
*   Overloading operator <<
*/
template <class item_type> 
Archive<item_type>& Archive<item_type>::operator<<(const item_type& item) {
    if(io_archive::isInOpen())
        io_archive::closeInStream();

    if(!io_archive::isOutOpen())
        io_archive::openOutStream(std::ios::out | std::ios::app);

    OArchive<item_type>::stream << item;
    OArchive<item_type>::stream << " ";
    return *this;
}

/**
*   Overloading operator >> 
*/
template <class item_type> 
Archive<item_type>& Archive<item_type>::operator>>(item_type& item) { 
    if(io_archive::isOutOpen())
        io_archive::closeOutStream();

    if(!io_archive::isInOpen())
        io_archive::openInStream(std::ios::in);

    IArchive<item_type>::stream >> item;
    return *this;
}

