#include "game.h"
#include "blocks.h"
#include <random>
Game::Game(){
    grid = Grid();
    gameOver = false;
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock(); 
}

Block Game::GetRandomBlock(){
    if (blocks.empty()){
        blocks = GetAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> Game::GetAllBlocks(){
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw(){
    grid.Draw();
    currentBlock.Draw();
}

void Game::HandleInput()
{
    int keyPressed = GetKeyPressed();
    if(gameOver && keyPressed != 0)
    {
        gameOver = false;
        Reset();
    }
    switch(keyPressed)
    {
        case KEY_LEFT:
        MoveBlockLeft();
        break;
        case KEY_RIGHT:
        MoveBlockRight();
        break;
        case KEY_DOWN:
        MoveBlockDown();
        break;
        case KEY_UP:
        RotateBlock();
        break;
    }
}

void Game::MoveBlockLeft()
{
    if(!gameOver)
    {
    currentBlock.Move(0,-1);
    if(isBlockOutside() || !BlockFits())
    {
        currentBlock.Move(0,1);
    }
    }
}
void Game::MoveBlockRight()
{
    if (!gameOver)
    {
    currentBlock.Move(0,1);
    if(isBlockOutside() || !BlockFits()){
        currentBlock.Move(0,-1);
    }
    }
}
void Game::MoveBlockDown()
{
    if (!gameOver)
    {
    currentBlock.Move(1,0);
    if(isBlockOutside() || !BlockFits()){
        currentBlock.Move(-1,0);
        LockBlock();
    }
    }
}


bool Game::isBlockOutside()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item : tiles)
    {
        if(grid.isCellOutside(item.r, item.c))
        {
            return true;
        }
    }
    return false;
}

void Game::RotateBlock()
{
    if (!gameOver)
    { 
    currentBlock.Rotate();
    if(isBlockOutside() || !BlockFits())
    {
        currentBlock.UndoRotation();
    }
    }
}

void Game::LockBlock()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item : tiles)
    {
        grid.grid[item.r][item.c] = currentBlock.id;
    }
    grid.ClearFullRows();
    currentBlock = nextBlock;
    nextBlock = GetRandomBlock();
    if (BlockFits() == false)
    {
        gameOver = true;
    }
}

bool Game::BlockFits()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item : tiles)
    {
        if (grid.isCellOutside(item.r, item.c))
        {
            return false;
        }
        if(grid.IsCellEmpty(item.r, item.c) == false)
        {
            return false;
        }
        
    }
    return true;
    
}

void Game::Reset()
{
    grid.Initialize();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}
