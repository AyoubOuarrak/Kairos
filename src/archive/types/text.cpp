#include "../../include/archive/types/text.h"

namespace kairos {
namespace archive {

/**
*   Default construct of the text archive
*/
TextArchive::TextArchive() : Archive() {
    
}

/**
*   Copy operator of text archive
*/
TextArchive::TextArchive(const TextArchive&) {
    
}

/** 
*   Sssignment operator 
*/
Archive TextArchive::operator=(const TextArchive&) {
    
}

/**
*   Default distructor 
*/
TextArchive::~TextArchive() {

}

/** 
*   Put int in the text archive
*/
void TextArchive::put(int src) {
    outStream << src << " " ;
}

/** 
*   Put long in the text archive
*/
void TextArchive::put(long src) {
    outStream << src << " ";
}

/** 
*   Put long long in the text archive
*/
void TextArchive::put(long long src) {
    outStream << src << " ";
}

/** 
*   Put double in the text archive
*/  
void TextArchive::put(double src) {
    outStream << src << " "; 
}
 
/** 
*   Put char in the text archive
*/     
void TextArchive::put(char src) {
    outStream << src << " "; 
}

/** 
*   Put bool in the text archive
*/     
void TextArchive::put(bool src) {
    outStream << src << " "; 
}

/** 
*   Empty body for binary serialization
*/ 
void TextArchive::put(char* byt, std::size_t sz) {
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
*   Get bool from the archive 
*/
void TextArchive::get(bool& dest) {
    inStream >> dest;
}

/** 
*   Get bool from the archive 
*/
void TextArchive::get(char& dest) {
    inStream >> dest;
}

/** 
*   Empty body for binary serialization
*/ 
void TextArchive::get(char* byt, std::size_t sz) {
    // empty body
}

}
}