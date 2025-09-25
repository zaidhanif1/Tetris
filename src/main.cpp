#include <raylib.h>
#include "game.h"
int main() 
{
    Color darkBlue = {44, 44, 127, 255};
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Grid grid = Grid();
    grid.Print();

    Game game = Game();

    while(WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();

    }
    CloseWindow();
}