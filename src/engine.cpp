#include <chrono>
#include <string>
#include <iostream>
#include "raylib.h"

#include "engine.hpp"

namespace chr = std::chrono;

namespace pe {

Engine::Engine()
    : m_last_frame(chr::system_clock::now()),
      m_last_physics_frame(chr::system_clock::now()),
      dt{10}
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

    const auto now = chr::system_clock::now();
    const chr::duration<float> curr_dt = now - m_last_physics_frame;
    if (curr_dt >= dt)
    {
        m_scene.update_physics(curr_dt.count());
        m_last_physics_frame = now;
    }

    m_scene.late_update();
}

void Engine::set_time_scale(const float time_scale)
{
    m_time_scale = time_scale;
}


}
