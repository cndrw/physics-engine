
#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "scene.hpp"

namespace  pe {

class Engine final
{
    public:
    Engine() = default;
    void CreateScene() const;
    void Update();
    void SetTimeScale(float time_scale);

    private:
    Scene m_scene;
};

};

#endif //ENGINE_HPP
