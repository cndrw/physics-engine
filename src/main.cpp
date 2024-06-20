#include "raylib.h"

#include "engine.hpp"

// 100px == 1m

// TODO:
// interpolation and more robust fixed time system?
// first (some?) dt that arrive for rigidbody are way out of scale (should be around 0.01s)
// more sophisticatied ground constrain
// better solution with transform (maybe?)

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
        DrawRectangle(0, 0, 50, 50, ORANGE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}