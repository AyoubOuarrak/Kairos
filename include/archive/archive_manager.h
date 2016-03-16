#ifndef ARCHIVE_ARCHIVE_MANAGER_H
#define ARCHIVE_ARCHIVE_MANAGER_H

#include "archive.h"
#include <string>

namespace kairos {
namespace archive {

class ArchiveFactory;

/**
*   Archive Manager class, provide archives registration
*/
class ArchiveManager : public Archive {
private:
    /** map of archives identified by their name */
    static std::map<std::string, ArchiveFactory*> archives;

public:
    /**
    *   register a new archive
    */
    static void registerType(const std::string& name, ArchiveFactory* archive);

protected:
    /**
    *   get a specific archive
    */
    static Archive* get(const std::string& name);
};

/**
*   Abstract archive factory class
*/
class ArchiveFactory {
public:
    virtual Archive* create() = 0;
};

}
}
#endif