/*

Has data type for rubix cube and will allow user to move the cube

Linux:
    g++ main.cpp cube.cpp -Wno-subobject-linkage && ./a.out
Windows:
    g++ main.cpp cube.cpp -Wno-subobject-linkage | start a.exe

*/

#include "cube.h"

int main()
{
    Cube c;

    c.moveLeft();
    
    std::cout << std::endl;

    c.printCube();

    for (int i: {0, 2, 3, 1, 4})
    {
        c.printFace(i);
    }

    return 0;
}