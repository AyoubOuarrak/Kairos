
Archive::Archive() : IArchive<int>(), OArchive<int>(), _archivePath(".") {
 
}

Archive::Archive(std::string path) : IArchive<int>(), OArchive<int>() {
    _archivePath = path;
}

Archive::~Archive() {
    
}

Archive& Archive::operator<<(const int& item) {
    OArchive::stream << item;
    OArchive::stream << " ";
    return *this;
}

Archive& Archive::operator>>(int& item) { 
    IArchive::stream >> item;
    return *this;
}

