#include "cube.h"

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
    // VS Code doesn't like this
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
    move(clockwise, 'R', {{0, 1, 3, 2, 0}, {2, 3, 1, 0, 2}}, {2, 5, 8}, 4);
}

void Cube::moveLeft(bool clockwise)
{
    move(clockwise, 'L', {{0, 1, 3, 2, 0}, {2, 3, 1, 0, 2}}, {0, 3, 6}, 5);
}

void Cube::moveTop(bool clockwise)
{
    move(clockwise, 'T', {{0, 5, 3, 4, 0}, {4, 3, 5, 0, 4}}, {0, 1, 2}, 1);
}

void Cube::moveBottom(bool clockwise)
{
    move(clockwise, 'B', {{0, 5, 3, 4, 0}, {4, 3, 5, 0, 4}}, {6, 7, 8}, 2);
}

void Cube::moveFront(bool clockwise)
{
    move(clockwise, 'B', {{5, 1, 4, 2, 5}, {2, 4, 1, 5, 2}}, {2, 5, 8}, 0);
}

void Cube::moveBack(bool clockwise)
{
    move(clockwise, 'B', {{5, 1, 4, 2, 5}, {2, 4, 1, 5, 2}}, {0, 3, 6}, 3);
}

/*
* Clockwise: Defines whether to move the side clockwise or counterclockwise
* SideChar: The character to be printed out for the side (i.e., Right: 'R', Left: 'L')
* SingleRowOrder: Order of the faces are in the single row that is being moved
* SquareIds: The ID of the squares that are going to be moved in the singleroworder based on the 0-8 vector they are held in
* FaceToRotate: ID of the face that needs to be rotated
*/

void Cube::move(bool clockwise, char sideChar, vector<vector<int>> singleRowOrder, vector<int> squareIds, int faceToRotate)
{
    // Creates temp for setting the next face to the correct colors
    vector<Colors> temp;

    // Based on the order of the numbers in the color values
    vector<int> order;
    
    if (clockwise) {
        order = singleRowOrder.at(0);
        std::cout << sideChar;
    } else {
        order = singleRowOrder.at(1);
        std::cout << sideChar << "'";
    }

    for (int i = 0; i < order.size() - 1; i++)
    {
        // Save nextFace in order to generate next face for next loop
        Face nextFace = faces.at(order.at(i + 1));
        Face& nextFaceAlter = faces.at(order.at(i + 1));
        Face& currentFace = faces.at(order.at(i));

        if (i == 0) {
            nextFaceAlter.v.at(squareIds.at(0)) = currentFace.v.at(squareIds.at(0));
            nextFaceAlter.v.at(squareIds.at(1)) = currentFace.v.at(squareIds.at(1));
            nextFaceAlter.v.at(squareIds.at(2)) = currentFace.v.at(squareIds.at(2));
        } else {
            nextFaceAlter.v.at(squareIds.at(0)) = temp.at(0);
            nextFaceAlter.v.at(squareIds.at(1)) = temp.at(1);
            nextFaceAlter.v.at(squareIds.at(2)) = temp.at(2);
        }

        temp = {nextFace.v.at(squareIds.at(0)), nextFace.v.at(squareIds.at(1)), nextFace.v.at(squareIds.at(2))};
    }

    // Rotates the right face
    Face& rFace = faces.at(faceToRotate);
    vector<Colors> currentColors = faces.at(faceToRotate).v;

    int counter = 0;

    if (clockwise)
    {
        order = {6, 3, 0, 7, 4, 1, 8, 5, 2};
    } else {
        order = {2, 5, 8, 1, 4, 7, 0, 3, 6};
    } 

    for (int i: order)
    {
        rFace.v.at(counter) = currentColors.at(i);
        counter++;
    }
}