/**
*   Overloading operator <<
*/ 
template <class item_type>
void Archive::add(const item_type& item) {
    if(io_archive::isInOpen())
        io_archive::closeInStream();

    if(!io_archive::isOutOpen())
        io_archive::openOutStream(std::ios::out | std::ios::app);

    OArchive::stream << item;
    OArchive::stream << " ";
    return *this;
}

/**
*   Overloading operator >> 
*/ 
template <class item_type>
item_type Archive::get() { 
    if(io_archive::isOutOpen())
        io_archive::closeOutStream();

    if(!io_archive::isInOpen())
        io_archive::openInStream(std::ios::in);

    IArchive::stream >> item;
    return *this;
}