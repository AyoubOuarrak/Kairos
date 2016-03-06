
/**
*   Default constructor 
*/
template <class item_type>
Archive<item_type>::Archive() : IArchive<item_type>(), OArchive<item_type>(), _archivePath(".") {
 
}

/**
*   Second constructor 
*/
template <class item_type>
Archive<item_type>::Archive(std::string path) : IArchive<item_type>(), OArchive<item_type>() {
    _archivePath = path;
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
    if(IArchive<item_type>::isOpen())
        IArchive<item_type>::closeStream();

    if(!OArchive<item_type>::isOpen())
        OArchive<item_type>::openStream(std::ios::out | std::ios::app);

    OArchive<item_type>::stream << item;
    OArchive<item_type>::stream << " ";
    return *this;
}

/**
*   Overloading operator >> 
*/
template <class item_type>
Archive<item_type>& Archive<item_type>::operator>>(item_type& item) { 
    if(OArchive<item_type>::isOpen())
        OArchive<item_type>::closeStream();

    if(!IArchive<item_type>::isOpen())
        IArchive<item_type>::openStream(std::ios::in);

    IArchive<item_type>::stream >> item;
    return *this;
}

