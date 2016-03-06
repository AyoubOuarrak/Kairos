
// checkpoint 

/*

PlayerProfile myPlayerProfile;
 
// Serialize and write to a file.

std::ofstream ofs("myPlayerProfile.dontlookhere");
boost::archive::text_oarchive oa(ofs);
oa << myPlayerProfile;
 
// Deserialize.

{
    std::ifstream ifs("myPlayerProfile.dontlookhere");
    boost::archive::text_iarchive ia(ifs);
    ia >> myPlayerProfile;

*/
//-------------------------------
/*

class A : public Serializable {
    int a, b, c;
    ......
    void serialize(const Archive& arr) {
        arr << a << b << c;
        // or
        arr.save(a);
        arr.save(b);
        arr.save(c);
    }
}



//********* Serializable ***********
class Serializable {
private:
protected:
    serialize(const Archive& arr);

public:

};



//********* ClassTest ***********
class ClassTest : public Serializable {
private:
    int _id;

    void serialize(const Archive& arr) {
        arr << _id;
    }

public:
    ClassTest() = default;
    ClassTest(int id);
    int getID();
};
*/



#include "../include/archive/archive.h"
#include <iostream>

using namespace kairos;
using namespace archive;

int main() {
    Archive<char> arr;

    arr << 's' << 'g';

    char a, b;

    arr >> a >> b;


    std::cout << a << " " << b << std::endl;
}




