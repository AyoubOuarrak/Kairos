#include "../kairos.h"

using namespace kairos;
using namespace serialization;

/**
 *  1) TEST BINARY SERIALIZATION USING BUILTIN ARCHIVE
 */
class User : public Serializable, public Serialization {
private:
    int id;
    int age;

public:
    User() {
        id = 0;
        age = 0;
        registerType(this);
    };
    
    User(int id_, int age_)  {
        id = id_;
        age = age_;
        registerType(this);
    }

    void set(int id_, int age_) {
        id = id_;
        age = age_;
    }

    void get() {
        std::cout << id << " " << age;
    }

    ~User() {};

    void serialize() {
        BuiltIn archive;
        archive << id << age;
    }

    void deserialize() {
       // BuiltIn native;
       // native >> id >> age;
    }
};

/**
*  3) TEST VECTOR SERIALIZATION
*/
class Fizz : public Serializable, public Serialization {
private:
    std::vector<int> v;

public:
    Fizz() {
        v.push_back(2);
        v.push_back(9);
        v.push_back(123);
        v.push_back(29342);
        v.push_back(12);
        registerType(this);
    }

    void serialize() {
        Vector vectorSer;
        vectorSer << v;
    }

    void deserialize() {
        //Vector vectorSer;
        //vectorSer >> v;
    }
};

int main() {
    User* user = new User(0, 23);
    Fizz fizz;

    try {
        Serialization::createCheckpoint(user);
        Serialization::createCheckpoint(&fizz);

    } catch (SerializationException* exp) {
        std::cout << exp->what() << std::endl;
    }

    Serialization::restore<User>();

}


