#pragma once
using namespace std;
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block {           // Parent class for different shaped blocks
    public:
        Block();
        void Draw(int offsetX, int offsetY);
        void Move(int rows, int columns);
        vector<Position> GetCellPositions();
        void Rotate();
        void UndoRotation();
        int id;
        map < int, vector<Position>> cells;

    private:
        int cellSize;
        int currentRotation;
        vector<Color> colors;
        int rowOffset;
        int columnOffset;

};