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

/**
 *  2) TEST TEXT SERIALIZATION USING BUILTIN ARCHIVE
 */
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
    }

    void serialize() {
        /** by default use a text archive */
        Vector vectorSer;

        vectorSer << v;
    }
};

int main() {
    User* user = new User(0, 23);
    Player* player = new Player(3.43);
    Player player0;
    Fizz fizz;

    Serialization::createCheckpoint(user);
    Serialization::createCheckpoint(player);
    Serialization::createCheckpoint(&player0);
    Serialization::createCheckpoint(&fizz);

    
}


