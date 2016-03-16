#include "../../include/archive/archive_manager.h"


/**
*   Macro to register new archives
*/
#define REGISTER_ARCHIVE(klass)                        \
class klass##Factory : public ArchiveFactory {  \
public:                                                \
    klass##Factory() {                                 \
        ArchiveManager::registerType(#klass, this);    \
    }                                                  \
    virtual ArchiveManager* create() {                 \
        return new klass();                            \
    }                                                  \
};                                                     \
static klass##Factory global_##klass##Factory;


/**
*   create a new archive from the factory
*/
ArchiveManager* ArchiveManager::create(const std::string& name) {
    return archives[name]->create();
}

/**
*   register a new archive
*/
static void ArchiveManager::registerType(const std::string& name, ArchiveManagerFactory* archive) {
    archives[name] = archive;
}

/**
*   return a specific archive
*/
static Archive* get(const std::string& name) {
    return archives[name];
}
