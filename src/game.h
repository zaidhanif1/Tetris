#pragma once
#include "grid.h"
#include "block.h"
class Game{
    public:
        Game();
        Block GetRandomBlock();
        std::vector<Block> GetAllBlocks();
        void Draw();
        Grid grid;

    private:
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
};