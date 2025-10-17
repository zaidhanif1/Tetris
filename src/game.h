#pragma once
#include "grid.h"
#include "block.h"
class Game{
    public:
        Game();
        Block GetRandomBlock();
        std::vector<Block> GetAllBlocks();
        void Draw();
        void HandleInput();
        void MoveBlockLeft();
        void MoveBlockRight();
        void MoveBlockDown();
        bool gameOver;
        Grid grid;

    private:
        bool isBlockOutside();
        void RotateBlock();
        void LockBlock();
        bool BlockFits();
        void Reset();
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
};