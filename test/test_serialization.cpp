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

    void serialize(Archive& archive) {
        archive << id << age;
    }

    void deserialize(Archive& archive) {
        archive >> id >> age;
    }
};

/**
*  3) TEST VECTOR SERIALIZATION
*/
class Fizz : public Serializable, public Serialization {
private:
    float v;
    int a;

public:
    Fizz() {
        v = 0.0;
        a = 0;
        registerType(this, Serialization::BINARY);
    }

    Fizz(float _v, int _a) {
        v = _v;
        a = _a;
        registerType(this, Serialization::BINARY);
    }

    void serialize(Archive& archive) {
        archive << v << a;
    }

    void deserialize(Archive& archive) {
        archive >> v >> a;
    }
};

int main() {
    User* user = new User(0, 23);
    User* user2 = new User(4, 6);

    Fizz fizz(3.2, 1);

    try {
        Serialization::createCheckpoint(user);
        Serialization::createCheckpoint(user2);
        Serialization::createCheckpoint(&fizz);

    } catch (SerializationException* exp) {
        std::cout << exp->what() << std::endl;
    }

   /* User user3;
    try {
        user3 = Serialization::restore<User>();

    } catch (SerializationException* exp) {
        std::cout << exp->what() << std::endl;
    }

    user3.get();*/

}


