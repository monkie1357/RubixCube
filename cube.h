#include <vector>
#include <iostream>

using std::vector;

namespace CubeData {
    enum Colors {
        Red = 'R',
        White = 'W',
        Yellow = 'Y',
        Orange = 'O',
        Blue = 'B',
        Green = 'G'
    };

    namespace {
        struct Face {
            vector<Colors> v;
        };
    }

    // Defines 3x3 Cube
    class Cube {
    public:
        Cube();
        void printCube();
        void printFace(int num);
        void printRow(const vector<char> &row);
        
        // Functions to move the sides of the cube
        void moveRight(bool clockwise = true);

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
    };
};