#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include "transform.hpp"

namespace pe {

class Scene final
{
    public:
    void AddObject(const Transform& obj);
    void RemoveObject(const Transform& obj);
    void ClearScene();
    private:
    std::vector<pe::Transform> m_objects;
};

}


#endif //SCENE_HPP
