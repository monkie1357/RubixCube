#include "cube.h"

using namespace CubeData;

Cube::Cube() {
    for ( Colors c: {Red, White, Yellow, Orange, Blue, Green} )
    {
        Face face;

        for (int i = 0; i < 9; i++)
        {
            face.v.push_back(c);
        }

        faces.push_back(face);
    }
}

void Cube::printCube()
{
    for (Face face: faces)
    {
        std::cout << "{ ";
        for (char c: face.v)
        {
            std::cout << c << " ";
        }
        std::cout << "}" << std::endl;
    }
}

void Cube::printRow(const vector<char> &row)
{
    std::cout << "| " << row.at(0) << " | " << row.at(1) << " | " << row.at(2) << " |" << std::endl;
}

void Cube::printFace(int num)
{
    Face f = faces.at(num);
    vector<Colors>& c = f.v;
    std::cout << std::endl << "Displaying Face: " << num << std::endl << std::endl;
    std::cout << "-------------" << std::endl;
    printRow({c.at(0), c.at(1), c.at(2)});
    std::cout << "-------------" << std::endl;
    printRow({c.at(3), c.at(4), c.at(5)});
    std::cout << "-------------" << std::endl;
    printRow({c.at(6), c.at(7), c.at(8)});
    std::cout << "-------------" << std::endl << std::endl;
}

void Cube::moveRight(bool clockwise)
{
    // TODO: Implement counter clockwise


    // Creates temp for setting the next face to the colors
    vector<Colors> temp;

    // Based on the order of the numbers in the color values
    vector<int> order;
    
    if (clockwise) {
        order = {0, 1, 3, 2, 0};
        std::cout << "R";
    } else {
        order = {2, 3, 1, 0, 2};
        std::cout << "R'";
    }

    for (int i = 0; i < order.size() - 1; i++)
    {
        // Save nextFace in order to generate next face for next loop
        Face nextFace = faces.at(order.at(i + 1));
        Face& nextFaceAlter = faces.at(order.at(i + 1));
        Face& currentFace = faces.at(order.at(i));

        if (i == 0) {
            nextFaceAlter.v.at(2) = currentFace.v.at(2);
            nextFaceAlter.v.at(5) = currentFace.v.at(5);
            nextFaceAlter.v.at(8) = currentFace.v.at(8);
        } else {
            nextFaceAlter.v.at(2) = temp.at(0);
            nextFaceAlter.v.at(5) = temp.at(1);
            nextFaceAlter.v.at(8) = temp.at(2);
        }

        temp = {nextFace.v.at(2), nextFace.v.at(5), nextFace.v.at(8)};
    }

    // Rotates the right face
    Face& rFace = faces.at(4);
    vector<Colors> currentColors = faces.at(4).v;

    int counter = 0;
    for (int i: {6, 3, 0, 7, 4, 1, 8, 5, 2})
    {
        rFace.v.at(counter) = currentColors.at(i);
        counter++;
    }
}