#include <iostream>
#include <types/text.h>

namespace kairos {
namespace archive {

/**
*   Default construct of the text archive
*/
TextArchive::TextArchive() {

}

/**
*   Constructor that open an input archive with the given filename
*/
TextArchive::TextArchive(std::string fileName) : Archive(fileName) {
    openInStream(fileName, std::ios::in);
}

/** 
*   Put int in the text archive
*/
void TextArchive::put(int src) {
    outStream << src << ' ';
}

/** 
*   Put long in the text archive
*/
void TextArchive::put(long src) {
    outStream << src << ' ';
}

/** 
*   Put long long in the text archive
*/
void TextArchive::put(long long src) {
    outStream << src << ' ';
}

/** 
*   Put double in the text archive
*/  
void TextArchive::put(double src) {
    outStream << src << ' ';
}

/**
*   Put float from archive
*/
void TextArchive::put(float src) {
    outStream << src << ' ';
}

/** 
*   Put char in the text archive
*/     
void TextArchive::put(char src) {
    outStream << src << ' ';
}

/**
*   Put string in the text archive
*/
void TextArchive::put(std::string src) {
    outStream << src << ' ';
}

/** 
*   Put bool in the text archive
*/     
void TextArchive::put(bool src) {
    outStream << src << ' ';
}

/** 
*   Empty body for binary serialization
*/
void TextArchive::put(char*, std::size_t) {
    // empty body
}

/** 
*   Get int from the archive 
*/
void TextArchive::get(int& dest) {
    inStream >> dest;
}
 
/** 
*   Get long from the archive 
*/   
void TextArchive::get(long& dest) {
    inStream >> dest;
}

/** 
*   Get long long from the archive 
*/    
void TextArchive::get(long long& dest) {
    inStream >> dest;
}
 
/** 
*   Get double from the archive 

*/   
void TextArchive::get(double& dest) {
    inStream >> dest;
}

/**
*   Get float from archive
*/
void TextArchive::get(float& dest) {
    inStream >> dest;
}

/** 
*   Get bool from the archive 
*/
void TextArchive::get(bool& dest) {
    inStream >> dest;
}

/** 
*   Get char from the archive
*/
void TextArchive::get(char& dest) {
    inStream >> dest;
}

/**
*   Get string from the archive
*/
void TextArchive::get(std::string& dest) {
    inStream >> dest;
}

/** 
*   Empty body for binary serialization
*/ 
void TextArchive::get(char*, std::size_t) {
    // empty body
}



}
}