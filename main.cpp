/*

Has data type for rubix cube and will allow user to move the cube

Linux:
    g++ main.cpp cube.cpp -Wno-subobject-linkage && ./a.out
Windows:
    g++ main.cpp cube.cpp -Wno-subobject-linkage | start a.exe

*/

#include "cube.h"

using namespace CubeData;

int main()
{
    Cube c;

    c.moveRight();
    
    std::cout << std::endl;

    c.printCube();

    for (int i: {0, 2, 3, 1})
    {
        c.printFace(i);
    }

    return 0;
}