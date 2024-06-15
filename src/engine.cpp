#include <chrono>
#include <string>
#include "raylib.h"

#include "engine.hpp"

namespace pe {

Engine::Engine()
    : m_last_frame(std::chrono::system_clock::now())
{
}

void Engine::draw_fps()
{
    const auto now = std::chrono::system_clock::now();
    const auto delta_s = std::chrono::duration<double>(now - m_last_frame).count();
    const int fps = static_cast<int>(1.0 / delta_s);
    const std::string time_str = "FPS: " + std::to_string(fps);

    DrawText(time_str.c_str(), 0, 0, 20, LIGHTGRAY);
    m_last_frame = now;
}

void Engine::update()
{
    draw_fps();

    m_scene.update();

}

void Engine::set_time_scale(float time_scale)
{
    m_time_scale = time_scale;
}


}
