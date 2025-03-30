#include <raylib.h>
#include "game.hpp"
#include "colors.h"

#define UI_OFFSET_PX 50

int main() {
    constexpr int screenWidth = 750;
    constexpr int screenHeight = 700;
    
    InitWindow(screenWidth + UI_OFFSET_PX, screenHeight + 2*UI_OFFSET_PX, "C++ Space Invaders");
    InitAudioDevice();


    SetTargetFPS(60);
    
    Game game;

    while (!WindowShouldClose()){
        UpdateMusicStream(game.music);
        game.HandleInput();
        game.Update();

        BeginDrawing();
        ClearBackground(BG_COLOR);
        game.DrawUI();
        game.Draw();
        EndDrawing();
    }
    
    CloseAudioDevice();
    CloseWindow();
}