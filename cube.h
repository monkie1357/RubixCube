#include <vector>
#include <iostream>

using std::vector;

enum Colors {
    Red = 'R',
    White = 'W',
    Yellow = 'Y',
    Orange = 'O',
    Blue = 'B',
    Green = 'G'
};

struct Face {
    vector<Colors> v;
};

// Defines 3x3 Cube
class Cube {
public:
    Cube();
    void printCube();
    void printFace(int num);
    void printRow(const vector<char> &row);
        
    /*
    * Functions to move the sides of the cube
    * Consists of six different movement types plus their idividual counterparts (clockwise/counter):
    * Top (T, T'), Bottom (B, B'), Right (R, R'), Left (L, L'), Front (F, F'), and Back (B, B')
    * ' is said as prime, so B' -> B Prime
    */

    void moveRight(bool clockwise = true);
    void moveLeft(bool clockwise = true);
    void moveTop(bool clockwise = true);
    void moveBottom(bool clockwise = true);
    void moveFront(bool clockwise = true);
    void moveBack(bool clockwise = true);

private:
    /*
    * Faces are defined as:
    *   0 -> Red -> Front
    *   1 -> White -> Top
    *   2 -> Yellow -> Bottom
    *   3 -> Orange -> Back
    *   4 -> Blue -> Right
    *   5 -> Green -> Left
    */
    vector<Face> faces;
    void move(bool clockwise, char sideChar, vector<vector<int>> singleRowOrder, vector<int> squareIds, int faceToRotate);
};