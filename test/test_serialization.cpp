#include "../kairos.h"
#include <vector>

using namespace kairos;
using namespace serialization;

/**
 *  1) TEST BINARY SERIALIZATION USING BUILTIN ARCHIVE
 */
class User : public Serializable, public Serialization {
private:
    int id;

public:
    User() {
        id = 0;
        registerType(this);
    };
    
    User(int id_)  {
        id = id_;
        registerType(this);
    }

    void set(int id_) {
        id = id_;
    }

    void get() {
        std::cout << id;
    }

    ~User() {};

    void serialize(Archive& archive) {
        archive << id;
    }

    void deserialize(Archive& archive) {
        archive >> id;
    }
};


int main() {
    User* user = new User(98);

    /** serialization */
    try {
        Serialization::createCheckpoint(user);

    } catch (SerializationException* exp) {
        std::cout << exp->what() << std::endl;
    }

    /** deserialization */
    try {
        auto users = Serialization::restore<User>();
        users.at("User1")->get();

    } catch (SerializationException* exp) {
        std::cout << exp->what() << std::endl;
    }
}


