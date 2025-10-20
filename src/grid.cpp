#include "grid.h"
#include <iostream>
#include "colors.h"

Grid::Grid(){ //constructor
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



bool Grid::isCellOutside(int r, int c)
{
    return r < 0 || r >= numRows || c < 0 || c >= numCols; //checks if cell is in bounds

}

bool Grid::IsCellEmpty(int r, int c)
{
    if (isCellOutside(r,c)) //if the current cell is outside the grid bounds
    {
        return false; //return false as it isn't usable (instatly making it empty)
    }
    return grid[r][c] == 0; //else if it is inside of the grid, check if the current cell is 0 (empty)
}

int Grid::ClearCompletedRows()
{
    int offset = 0; //
    for (int r = numRows-1; r>=0; r--)
    {
        if (isRowFull(r)) //if row is full, increment total offset we'll have to move rows above it.
        {
            ClearRow(r); //clear that row
            offset++; //increment offset
        }
        else if(offset > 0)
        {
            MoveRowDown(r, offset); //else if the row isn't full and the offset is greater than 0 (i.e there has been rows cleared beneath it)
        }
    } 
    return offset; //return how many rows we deleted (useful for switch )
}

void Grid::Draw(){
    for(int r = 0; r<numRows; r++){
        for (int c = 0; c<numCols; c++){
            int cellValue = grid[r][c];
            DrawRectangle(c * cellSize+11, r * cellSize+11, cellSize-1, cellSize-1, colors[cellValue]); // shift columns and rows to start at (11,11)
        }   //decrement cellSize by one pixel each to create gap between each cell
            //use the index to determine the color value
    }
}

bool Grid::isRowFull(int r)
{
    for (int c = 0; c < numCols; c++)
    {
        if(grid[r][c] == 0)
        {
            return false; //check if the row is full by checking if the entire row doesn't have 0's
        }
    }
    return true;
}

void Grid::ClearRow(int r)
{
    for (int c = 0; c < numCols; c++)
    {
        grid[r][c] = 0; //make curr row set to all 0's
    }
    
}

void Grid::MoveRowDown(int r, int numRows) //numRows is the amount of rows the user has cleared
{
    for (int c = 0; c < numCols; c++)
    {
        grid[r+numRows][c] = grid[r][c];
        grid[r][c] = 0;
    }
}
