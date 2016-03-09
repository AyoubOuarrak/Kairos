
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



#include "../include/archive/type/vector.h"
#include <iostream>
#include <vector>

using namespace kairos;
using namespace archive;

int main() {
    std::vector<int> array;
    for(int i = 0; i < 10; ++i)
        array.push_back(i*2);

    VectorArchive<int> arr;

    arr << array;

    std::vector<int> array1;

    arr >> array1;

    for(int i = 0; i < array1.size(); ++i)
        std::cout << array1[i] << std::endl;
}




