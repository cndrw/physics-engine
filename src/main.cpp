#include "raylib.h"

#include "engine.hpp"

// 100px == 1m

// TODO:
// implement arena for scene object
// shape construction not working atm -> std::async not really working out (tend for own architecture for handling with this input)
// interpolation and more robust fixed time system?
// first (some?) dt that arrive for rigidbody are way out of scale (should be around 0.01s)
// better solution with transform (maybe?)
// proper collison resolving

int main()
{
    pe::Engine engine;
    InitWindow(800, 450, "pyhsics-engine");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        engine.update();
        DrawRectangle(0, 400, 800, 100, BLUE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}