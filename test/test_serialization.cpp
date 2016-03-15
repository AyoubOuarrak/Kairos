#include "../include/serialization/serializable.h"
#include <iostream>
#include <string>

using namespace kairos;
using namespace serialization;

/**
*   CASE USE OF CLASS SERIALIZABLE
*/
/*
template <typename... Types> 
class Serializable {
private:
    std::map<> map_of_all_object_to_serialize;

public:
    
protected:
    template <class T>
    void serialize(Archive<T> archive);  // create archive according to types list


    void saveAll() {
        //write the map in file
    }


};
*/
/**
*   TEST CLASS
*/
/*
class test : public Serializable<int, float, std::vector<int> > {
private:
    int a;
    float c;
    std::vector<int> v;

public:

    test() {
        a = 2;
        c = 2.4;
        for(int i = 0; i < 10; ++i)
        v.push_back(i*4); 
    }

    //TODO: just one function serialize,
    //TODO: create objects in the serializable class
    void serialize(Archive<int>* archive) {
        archive = new Archive<int>;
        *archive << a;    // dont write on file, just add the value to the map
    } 

    void serialize(Archive<float>* archive) {
        archive = new Archive<float>;
        *archive << c;    // dont write on file, just add the value to the map
    }

    void serialize(Archive<std::vector<int> >* archive) {
        archive = new Archive<std::vector<int> >;
        *archive << v;     // dont write on file, just add the value to the map
    }

    // should look like thiz
    void serialize(Archive archive) {
        archive << a;
        archive << c;
        archive << v;
    }

};
*/

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

    //......
    void serialize(Archive<int>& archive) {
        archive << id << age;
    }

    void serialize(Archive<std::string>& archive) {
        archive << nick;
    }
};

int main() {
    User* user = new User("lol", 0, 23);
}


