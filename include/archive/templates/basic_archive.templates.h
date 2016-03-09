
/**
*   Default construct of the basic archive, it set the name of the archive
*/
template <class item_type>
Basic_Archive<item_type>::Basic_Archive() : archiveName("archive") {
    inStream.open(archiveName, std::ios::in);
    outStream.open(archiveName, std::ios::out);
}

/**
*   Second construct of the basic archive, it set the name of the archive from parameter
*   param archiveName archive name
*/
template <class item_type>
Basic_Archive<item_type>::Basic_Archive(std::string _archiveName) {
    archiveName = _archiveName;
    inStream.open(archiveName, std::ios::in);
    outStream.open(archiveName, std::ios::out);
}

/**
*   Default distruct of the basic archive
*/
template <class item_type> 
Basic_Archive<item_type>::~Basic_Archive() {
    inStream.close();
    outStream.close();
}

/**
*   Return the name of the archive
*/
template <class item_type>
std::string Basic_Archive<item_type>::name() const {
    return archiveName;
}

/**
*   Default construct of the input archive, it open the input stream
*/
template <class item_type>
IArchive<item_type>::IArchive() : Basic_Archive<item_type>() {
    
}

/**
*   Second construct of the input archive, it set the stream from parameter
*   param stream input stream
*/
template <class item_type>
IArchive<item_type>::IArchive(std::ifstream stream) {
    Basic_Archive<item_type>::inStream = stream;
}

/**
*   Default distruct of the input archive
*/
template <class item_type> 
IArchive<item_type>::~IArchive() {
    Basic_Archive<item_type>::inStream.close();
}

/**
*   Return if the input stream is open
*/
template <class item_type>
bool Basic_Archive<item_type>::isInOpen() const {
    return inStream.is_open();
}

/**
*   Return if the output stream is open
*/
template <class item_type>
bool Basic_Archive<item_type>::isOutOpen() const {
    return outStream.is_open();
}

/** 
*   Open the input stream 
*/
template <class item_type>
void Basic_Archive<item_type>::openInStream() {
    inStream.open(archiveName, std::ios::in);
}

/** 
*   Open the output stream 
*/
template <class item_type>
void Basic_Archive<item_type>::openOutStream() {
    outStream.open(archiveName, std::ios::out);
}

/** 
*   Open the input stream with a different mode 
*/
template <class item_type>
void Basic_Archive<item_type>::openInStream(std::ios_base::openmode mode) {
    inStream.open(archiveName, mode);
}

/** 
*   Open the output stream with a different mode 
*/
template <class item_type>
void Basic_Archive<item_type>::openOutStream(std::ios_base::openmode mode) {
    outStream.open(archiveName, mode);
}

/** 
*   Open the input stream with a different mode 
*/
template <class item_type>
void Basic_Archive<item_type>::openInStream(std::string archive_name, 
                                               std::ios_base::openmode mode) {
    inStream.open(archive_name, mode);
}

/** 
*   Open the output stream with a different mode 
*/
template <class item_type>
void Basic_Archive<item_type>::openOutStream(std::string archive_name, 
                                                std::ios_base::openmode mode) {
    outStream.open(archive_name, mode);
}

/** 
*   Close the input stream 
*/
template <class item_type>
void Basic_Archive<item_type>::closeInStream() {
    inStream.close();
}

/** 
*   Close the input stream 
*/
template <class item_type>
void Basic_Archive<item_type>::closeOutStream() {
    outStream.close();
}

/**
*   Default construct of the output archive, it open the output archive
*/
template <class item_type>
OArchive<item_type>::OArchive() : Basic_Archive<item_type>() {

}

/**
*   Second construct of the output archive, it set the output stream from parameter
*   param stream output stream
*/
template <class item_type>
OArchive<item_type>::OArchive(std::ofstream stream) {
    Basic_Archive<item_type>::outStream = stream;
}

/**
*   Default output archive distructor
*/
template <class item_type> 
OArchive<item_type>::~OArchive() {
    Basic_Archive<item_type>::outStream.close();
}
