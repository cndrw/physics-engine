
#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <chrono>
#include "scene.hpp"
#include "ui_handler.hpp"

namespace  pe {

namespace chr = std::chrono;

class Engine final
{
public:
    Engine();
    void create_scene() const;
    void update();
    void set_time_scale(float time_scale);

private:
    void draw_fps();

private:
    Scene m_scene;
    UIHandler m_ui_handler;
    chr::system_clock::time_point m_last_frame;
    chr::system_clock::time_point m_last_physics_frame;
    chr::milliseconds dt;
    float m_time_scale = 1.0;
};

}

#endif //ENGINE_HPP
