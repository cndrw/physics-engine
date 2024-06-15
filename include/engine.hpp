
#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <chrono>
#include "scene.hpp"

namespace  pe {

namespace chr = std::chrono;

class Engine final
{
    private:
    Scene m_scene;
    float m_time_scale = 1.0;
    chr::system_clock::time_point m_last_frame;



    public:
    Engine();
    void create_scene() const;
    void update();
    void set_time_scale(float time_scale);

    private:
    void draw_fps();
};

}

#endif //ENGINE_HPP
