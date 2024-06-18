#include "raylib.h"

#include "engine.hpp"

// 100px == 1m

// TODO:
// interpolation and more robust fixed time system?
// first (some?) dt that arrive for rigidbody are way out of scale (should be around 0.01s)
int main()
{
    pe::Engine engine;
    InitWindow(800, 450, "pyhsics-engine");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        engine.update();
        DrawRectangleLines(0, 0, 100, 100, BLUE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}