#include "../include/serialization/serializable.h"
#include "../include/serialization/serialization.h"
#include "../include/serialization/type/built_in.h"
#include <iostream>
#include <string>

using namespace kairos;
using namespace serialization;


class User : public Serializable, public Serialization {
private:
    int id;
    int age;
    uint16_t type_id;   // id returned by the Serializable class 

public:
    User() {
        type_id = registerType(this);
    };
    
    User(int id_, int age_)  {
        id = id_;
        age = age_;
        type_id = registerType(this);
    }

    ~User() {};

    /** Serializable method */
    void serialize() {
        /** get the type of archive from the archive manager */
        BuiltIn native;

        /** add data to the archive */
        native << id << age;
    }
};

int main() {
    User* user = new User(0, 23);

    Serialization::createCheckpoint(user);
}


