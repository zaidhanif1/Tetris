#include "block.h"
#include <vector>
#include "position.h"
#include "colors.h"

Block::Block(){
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
    x = 0;
    y = 0;
}

void Block::Draw(){
    std::vector<Position> tiles = GetCells();
    for (Position item: tiles){
        DrawRectangle(item.c * cellSize+1, item.r * cellSize+1, cellSize-1, cellSize-1, colors[id]);
    }
};

void Block::Move(int dx, int dy){
    x = dx;
    y = dy;
}

std::vector<Position> Block::GetCells(){
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;
    for (Position item: tiles){
        Position newPost = Position(item.r + x, item.c + y);
        movedTiles.push_back(newPost);
}
    return movedTiles;
};