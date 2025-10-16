#include "grid.h"
#include <iostream>
#include "colors.h"

Grid::Grid(){
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initialize();
    colors = GetCellColors();


}
void Grid::Initialize(){
    for(int r = 0; r<numRows; r++){
        for (int c = 0; c < numCols; c++){
            grid[r][c] = 0;
        }
    }
}

void Grid::Print(){
     for (int r = 0; r < numRows; r++){
        for (int c = 0; c < numCols; c++){

            std::cout << grid[r][c] << " ";
        }
        std::cout << std::endl;
     }
}

bool Grid::isCellOutside(int r, int c)
{
    if(r >= 0 && r < numRows && c >= 0 && c <numCols)
    {
        return false;
    }
    return true;
}

void Grid::Draw(){
    for(int r = 0; r<numRows; r++){
        for (int c = 0; c<numCols; c++){
            int cellValue = grid[r][c];
            DrawRectangle(c * cellSize+1, r * cellSize+1, cellSize-1, cellSize-1, colors[cellValue]);
        }
    }
}