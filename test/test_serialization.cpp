#include "../include/serialization/serializable.h"
#include <iostream>
#include <string>

using namespace kairos;
using namespace serialization;


class User : public Serializable {
private:
    int id;
    int age;
    uint16_t type_id;   // id returned by the Serializable class 

public:
    User() {
        type_id = registerType(this);
    };
    
    User(int id_, int age_)  {
        nick = nick_;
        id = id_;
        age = age_;
        type_id = registerType(this);
    }

    ~User() {};

    /** Serializable method */
    void serialize(Archive& arr) {
        /** get the type of archive from the archive manager */
        archive = new BuiltIn();

        /** add data to the archive */
        archive << id << age;
    }
};

int main() {
    User* user = new User(0, 23);

    Serialization::crateCheckpoint(user);
}


