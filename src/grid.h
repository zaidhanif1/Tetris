#pragma once
#include <vector>
#include <raylib.h>

class Grid{
    public:
    Grid();
    int grid[20][10];
    void Initialize();
    void Print();
    void Draw();

private:
    int numCols;
    int numRows;
    int cellSize;
    std::vector<Color> colors;

};
