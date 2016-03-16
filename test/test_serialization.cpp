#include "../include/serialization/serializable.h"
#include <iostream>
#include <string>

using namespace kairos;
using namespace serialization;


class User : public Serializable {
private:
    std::string nick;
    int id;
    int age;

public:
    User() { };
    
    ~User() { };
    
    User(std::string nick_, int id_, int age_)  {
        nick = nick_;
        id = id_;
        age = age_;
    }

    /** Serializable method */
    void serialize() {
        /** get the type of archive from the archive manager */
        Archive* archive = ArchiveManager.get("NativeSD");

        /** add data to the archive */
        archive.add<int>(id);
        archive.add<int>(age);
        archive.add<std::string>(nick);
    }
};

int main() {
    User* user = new User("lol", 0, 23);
}


