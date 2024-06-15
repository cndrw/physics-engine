#include "raylib.h"
#include <chrono>
#include <string>
#include <iostream>
#include <thread>

#include "engine.hpp"

auto last_time = std::chrono::system_clock::now();

void draw_fps() noexcept
{
    const auto now = std::chrono::system_clock::now();
    const auto delta_s = std::chrono::duration<double>(now - last_time).count();
    const int fps = static_cast<int>(1.0 / delta_s);
    const std::string time_str = "FPS: " + std::to_string(fps);

    DrawText(time_str.c_str(), 0, 0, 20, LIGHTGRAY);
    last_time = now;
}

int main()
{
    pe::Engine engine;
    InitWindow(800, 450, "pyhsics-engine");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        draw_fps();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}