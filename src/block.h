#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"



class Block{
    public:
        // Note: only declare member functions here. Put full method definitions
        // in the corresponding .cpp file to avoid multiple-definition linker errors.
        Block();
        void Draw();
        void Move(int dx, int dy);
        std::vector<Position> GetCells();
        int id;
        std::map<int, std::vector<Position>> cells;

    private:
        int cellSize;
        int rotationState;
        std::vector<Color> colors;
        int x;
        int y;

};