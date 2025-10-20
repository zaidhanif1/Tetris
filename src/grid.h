#pragma once
#include <vector>
#include <raylib.h>

class Grid{
    public:
    Grid();
    int grid[20][10]; //initialize the grid as a 2D array
    void Initialize(); //fills the entire grid with 0's
    bool isCellOutside(int r, int c); //guard for out of bounds
    bool IsCellEmpty(int r, int c); //check if the current cell is occupied with another cell
    int ClearCompletedRows(); //resets the entire grid to 0's
    void Draw(); 

private:
    bool isRowFull(int r); //checks if current row is completed
    void ClearRow(int r); //clear the current row
    void MoveRowDown(int r, int numRows); //move row down if there was a completed row beneath it
    int numCols; //class specific data 
    int numRows;
    int cellSize;
    std::vector<Color> colors;

};
