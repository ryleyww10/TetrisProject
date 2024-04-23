#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>
using namespace std;

double lastUpdateTime = 0;

bool EventTriggered(double interval) {                  // after interval time update game
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{

    InitWindow(500, 620, "raylib Tetris");      // setting size of window
    SetTargetFPS(60);                           // Necessary so that computer doesnt try to run it as fast as it can

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    Game game = Game();

    while(WindowShouldClose() == false) {
        game.HandleInput();
        if(game.score < 500) {                                  // Game speeds up after a certain score is reached
            if(EventTriggered(0.6)) {
               game.MoveBlockDown();
            }
        }
        else if(game.score >= 500 && game.score < 1500) {
            if(EventTriggered(0.3)) {
               game.MoveBlockDown();
            }
        }
        else {
            if(EventTriggered(0.15)) {
               game.MoveBlockDown();
            }
        }


        BeginDrawing();                         
        ClearBackground(lightBlue);                  // setting background color
        DrawTextEx(font, "Score", {365, 15}, 38, 2, BLACK);
        DrawTextEx(font, "Next", {370, 175}, 38, 2, BLACK);
        if(game.gameOver) {
            DrawTextEx(font, "Game Over", {320, 450}, 38, 2, BLACK);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, darkBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

        DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 38, 2, BLACK);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, darkBlue);
        game.Draw();
        EndDrawing();

    }
    

    CloseWindow();
}