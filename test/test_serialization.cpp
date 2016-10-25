#include "../kairos.h"
#include <vector>

using namespace kairos;
using namespace serialization;

/**
 *  TEST TEXT SERIALIZATION USING SCALAR TYPES
 */
class User : public Serializable, public Serialization {
private:
    int id;
    float a;
    std::string name;

public:
    User() {
        id = 0;
        a = 0.0;
        name = "";
        registerType(this);
    };
    
    User(int id_, float a_, std::string name_)  {
        id = id_;
        a = a_;
        name = name_;
        registerType(this);
    }

    void get() {
        std::cout << id << " " << a << " " << name << '\n';
    }

    ~User() {};

    void serialize(Archive& archive) {
        archive << id << a << name;
    }

    void deserialize(Archive& archive) {
        archive >> id >> a >> name;
    }
};

/**
 *  TEST BINARY SERIALIZATION USING FLOATING POINT TYPES
 */
class FizzBin : public Serializable, public Serialization {
private:
    float a;
    double b;
    char z;

public:
    FizzBin() {
        a = 0.0f;
        b = 0.0;
        z = 'a';
        registerType(this, SerializationFormats::BINARY);
    }

    FizzBin(float ff, double dd, char cc) {
        a = ff;
        b = dd;
        z = cc;
        registerType(this, SerializationFormats::BINARY);
    }

    void get() {
        std::cout << a << " " << b << " " << z;
    }

    void serialize(Archive& archive) {
        archive << a << b << z;
    }

    void deserialize(Archive& archive) {
        archive >> a >> b >> z;
    }

};

int main() {
    User* user = new User(98, 2.4, "Chico");
    FizzBin* fizz = new FizzBin(2.3, 2342.05, 'z');

    /** serialization */
    try {
        Serialization::createCheckpoint(user);
        Serialization::createCheckpoint(fizz);

    } catch (SerializationException* exp) {
        std::cout << exp->what() << std::endl;
    }

    /** deserialization */
    try {
        auto users = Serialization::restore<User>();
        users.at("User1")->get();

        auto fizzz = Serialization::restore<FizzBin>();
        fizzz.at("FizzBin1")->get();

    } catch (SerializationException* exp) {
        std::cout << exp->what() << '\n'
                  << exp->info() << '\n';
    }
}


