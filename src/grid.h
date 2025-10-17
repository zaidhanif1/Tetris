#pragma once
#include <vector>
#include <raylib.h>

class Grid{
    public:
    Grid();
    int grid[20][10];
    void Initialize();
    void Print();
    bool isCellOutside(int r, int c);
    bool IsCellEmpty(int r, int c);
    int ClearFullRows();
    void Draw();

private:
    bool isRowFull(int r);
    void ClearRow(int r);
    void MoveRowDown(int r, int numRows);
    int numCols;
    int numRows;
    int cellSize;
    std::vector<Color> colors;

};
