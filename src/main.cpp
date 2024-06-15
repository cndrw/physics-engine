#include "raylib.h"

#include "engine.hpp"

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