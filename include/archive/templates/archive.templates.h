
Archive::Archive() : IArchive<int>(), OArchive<int>(), _archivePath(".") {
 
}

Archive::Archive(std::string path) : IArchive<int>(), OArchive<int>() {
    _archivePath = path;
}

Archive::~Archive() {

}

Archive& Archive::operator<<(const int& item) {
    if(IArchive<int>::isOpen())
        IArchive<int>::closeStream();

    if(!OArchive<int>::isOpen())
        OArchive<int>::openStream(std::ios::out | std::ios::app);

    OArchive::stream << item;
    OArchive::stream << " ";
    return *this;
}

Archive& Archive::operator>>(int& item) { 
    if(OArchive<int>::isOpen())
        OArchive<int>::closeStream();

    if(!IArchive<int>::isOpen())
        IArchive<int>::openStream(std::ios::in);

    IArchive::stream >> item;
    return *this;
}

