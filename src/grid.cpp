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
    return r < 0 || r >= numRows || c < 0 || c >= numCols;

}

bool Grid::IsCellEmpty(int r, int c)
{
    if (isCellOutside(r,c))
    {
        return false;
    }
    return grid[r][c] == 0;
}

int Grid::ClearFullRows()
{
    int completed = 0;
    for (int r = numRows-1; r>=0; r--)
    {
        if (isRowFull(r))
        {
            ClearRow(r);
            completed++;
        }
        else if(completed > 0)
        {
            MoveRowDown(r, completed);
             
        }
    }
    return completed;
}

void Grid::Draw(){
    for(int r = 0; r<numRows; r++){
        for (int c = 0; c<numCols; c++){
            int cellValue = grid[r][c];
            DrawRectangle(c * cellSize+11, r * cellSize+11, cellSize-1, cellSize-1, colors[cellValue]);
        }
    }
}

bool Grid::isRowFull(int r)
{
    for (int c = 0; c < numCols; c++)
    {
        if(grid[r][c] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int r)
{
    for (int c = 0; c < numCols; c++)
    {
        grid[r][c] = 0;
    }
    
}

void Grid::MoveRowDown(int r, int numRows)
{
    for (int c = 0; c < numCols; c++)
    {
        grid[r+numRows][c] = grid[r][c];
        grid[r][c] = 0;
    }
}
