#include "grid.h"
#include <iostream>
using namespace std;
#include "colors.h"
// implementation file

Grid::Grid() {
    numRows = 20;
    numColumns = 10;
    cellSize = 30;
    Initialize();
    colors = GetCellColors();
}

void Grid::Initialize() {           // starts by setting the grid values to 0
    for(int row = 0; row < numRows; row++) {
        for(int column = 0; column < numColumns; column++) {
            grid[row][column] = 0;
        }
    }
}

void Grid::Print() {                  // method to print and check values on grid                          
    for(int row = 0; row < numRows; row++) {
        for(int column = 0; column < numColumns; column++) {
            cout << grid[row][column] << " ";
        }
        cout << endl;
    }
}


void Grid::Draw() {
    for(int row = 0; row < numRows; row++) {
        for(int column = 0; column < numColumns; column++) {
            int cellValue = grid[row][column];
            DrawRectangle(column * cellSize+11, row * cellSize+11, cellSize-1, cellSize-1, colors[cellValue]);  // (x, y, w, h, color)
        }
    }
}

bool Grid::IsCellOutside(int row, int column)
{
    if(row >= 0 && row < numRows && column >= 0 && column < numColumns) {
        return false;
    }
    return true;
}

bool Grid::IsCellEmpty(int row, int column)
{
    if(grid[row][column] == 0) {
        return true;
    }
    return false;
}

int Grid::ClearFullRows()
{
    int completed = 0;
    for(int row = numRows - 1; row >= 0; row--) {
        if(IsRowFull(row)) {
            ClearRow(row);
            completed++;
        }
        else if (completed > 0) {
            MoveRowDown(row, completed);
        }
    }
    return completed;
}

bool Grid::IsRowFull(int row)
{
    for(int column = 0; column < numColumns; column ++) {
        if(grid[row][column] == 0) {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row)
{
    for(int column = 0; column < numColumns; column++) {
        grid[row][column] = 0;
    }
}

void Grid::MoveRowDown(int row, int numRows)
{
    for(int column = 0; column < numColumns; column++) {
        grid[row + numRows][column] = grid[row][column];
        grid[row][column] = 0;
    }
}
