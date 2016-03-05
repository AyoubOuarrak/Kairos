
/**
*   Default construct of the basic archive, it set the name of the archive
*/
template <class item_type>
Basic_Archive<item_type>::Basic_Archive() : _archiveName("archive") {

}

/**
*   Second construct of the basic archive, it set the name of the archive from parameter
*   param archiveName archive name
*/
template <class item_type>
Basic_Archive<item_type>::Basic_Archive(std::string archiveName) {
    _archiveName = archiveName;
}

/**
*   Default distruct of the basic archive
*/
template <class item_type> 
Basic_Archive<item_type>::~Basic_Archive() {
    
}

/**
*   Return the name of the archive
*/
template <class item_type>
std::string Basic_Archive<item_type>::name() const {
    return _archiveName;
}

/**
*   Default construct of the input archive, it open the input stream
*/
template <class item_type>
IArchive<item_type>::IArchive() : Basic_Archive<item_type>() {
    stream.open(Basic_Archive<item_type>::name(), std::ios::in);
}

/**
*   Second construct of the input archive, it set the stream from parameter
*   param stream input stream
*/
template <class item_type>
IArchive<item_type>::IArchive(std::ifstream stream) {
    stream = stream;
}

/**
*   Default distruct of the input archive
*/
template <class item_type> 
IArchive<item_type>::~IArchive() {
    stream.close();
}

/**
*   Return if the input stream is open
*/
template <class item_type>
bool IArchive<item_type>::isOpen() const {
    return stream.is_open();
}

/** 
*   Open the input stream 
*/
template <class item_type>
void IArchive<item_type>::openStream() {
    stream.open(Basic_Archive<item_type>::name(), std::ios::in);
}

/** 
*   Open the input stream with a different mode 
*/
template <class item_type>
void IArchive<item_type>::openStream(std::ios_base::openmode mode) {
    stream.open(Basic_Archive<item_type>::name(), mode);
}

/** 
*   Open the input stream with a different mode 
*/
template <class item_type>
void IArchive<item_type>::openStream(std::string archive_name, std::ios_base::openmode mode) {
    stream.open(archive_name, mode);
}

/** 
*   Close the input stream 
*/
template <class item_type>
void IArchive<item_type>::closeStream() {
    stream.close();
}

/**
*   Default construct of the output archive, it open the output archive
*/
template <class item_type>
OArchive<item_type>::OArchive() : Basic_Archive<item_type>() {
    stream.open(Basic_Archive<item_type>::name(), std::ios::out);
}

/**
*   Second construct of the output archive, it set the output stream from parameter
*   param stream output stream
*/
template <class item_type>
OArchive<item_type>::OArchive(std::ofstream stream) {
    stream = stream;
}

/**
*   Default output archive distructor
*/
template <class item_type> 
OArchive<item_type>::~OArchive() {
    stream.close();
}

/**
*   Return if the output stream is open
*/
template <class item_type>
bool OArchive<item_type>::isOpen() const {
    return stream.is_open();
}

/** 
*   Open the output stream 
*/
template <class item_type>
void OArchive<item_type>::openStream() {
    stream.open(Basic_Archive<item_type>::name(), std::ios::out);
}

/** 
*   Open the ouput stream with a different mode 
*/
template <class item_type>
void OArchive<item_type>::openStream(std::ios_base::openmode mode) {
    stream.open(Basic_Archive<item_type>::name(), mode);
}

/** 
*   Open the ouput stream with a different mode 
*/
template <class item_type>
void OArchive<item_type>::openStream(std::string archive_name, std::ios_base::openmode mode) {
    stream.open(archive_name, mode);
}

/** 
*   Close the output stream 
*/
template <class item_type>
void OArchive<item_type>::closeStream() {
    stream.close();
}
