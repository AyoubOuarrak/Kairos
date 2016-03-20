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
    User() {
        registerType(this);
    };
    
    User(std::string nick_, int id_, int age_)  {
        nick = nick_;
        id = id_;
        age = age_;
        registerType(this);
    }

    ~User() {};

    /** Serializable method */
    void serialize(Archive& arr) {
        /** get the type of archive from the archive manager */
        archive = new Archive();

        /** add data to the archive */
        archive << id << age << nick;
    }
};

int main() {
    User* user = new User("lol", 0, 23);
}


