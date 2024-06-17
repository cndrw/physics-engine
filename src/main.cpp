#include "raylib.h"

#include "engine.hpp"

// TODO:
// interpolation and more robust fixed time system?
int main()
{
    pe::Engine engine;
    InitWindow(800, 450, "pyhsics-engine");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        engine.update();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}