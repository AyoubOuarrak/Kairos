#include "../include/serialization/serializable.h"
#include "../include/serialization/serialization.h"
#include "../include/serialization/type/built_in.h"

using namespace kairos;
using namespace serialization;


class User : public Serializable, public Serialization {
private:
    int id;
    int age;

public:
    User() {
        registerType(this);
    };
    
    User(int id_, int age_)  {
        id = id_;
        age = age_;
        registerType(this);
    }

    ~User() {};

    void serialize() {
        /** get the type of archive from the archive manager */
        BuiltIn native(new BinaryArchive);

        /** add data to the archive */
        native << id << age;
    }
};

class Player : public Serializable, public Serialization {
private:
    float score;

public:
    Player() {
        score = 0.0;
        registerType(this);
    };
    
    Player(float _score)  {
        score = _score;
        registerType(this);
    }

    ~Player() {};

    void serialize() {
        /** get the type of archive from the archive manager */
        BuiltIn native;

        /** add data to the archive */
        native << score;
    }
};

int main() {
    User* user = new User(0, 23);
    Player* player = new Player(3.43);
    Player player0;

    Serialization::createCheckpoint(user);
    Serialization::createCheckpoint(player);
    Serialization::createCheckpoint(&player0);

    
}


