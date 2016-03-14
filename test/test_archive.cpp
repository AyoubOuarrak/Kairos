#include "../include/archive/type/vector.h"
#include <iostream>
#include <vector>
#include <map>

using namespace kairos;
using namespace archive;

int main() {
    /** insert data */
    std::vector<int> v;
    for(int i = 0; i < 10; ++i)
        v.push_back(i*4);

    /** create an archive for vectors */
    Archive<std::vector<int>>* archive = new VectorArchive<int>();

    /** serializa the vector */
    *archive << v;

    /** create an empty vector */
    std::vector<int> v2;

    /** restore data into the vectors */
    *archive >> v2;

    /** print vector */
    for(int i = 0; i < array1.size(); ++i)
        std::cout << v2[i] << std::endl;
}




