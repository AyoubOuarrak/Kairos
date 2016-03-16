#include "../../include/archive/archive_manager.h"



/**
*   register a new archive
*/
static void ArchiveManager::register(const std::string& name, Archive* archive) {
    archives[name] = archive;
}

/**
*   create a new archive from the identified name
*/
static Archive* ArchiveManager::get(const std::string& name) {
    return new archives[name];
}