#include "scene.hpp"

#include "shapes.hpp"
#include "rigidbody.hpp"

namespace pe {

Scene::Scene()
{
    pe::Rectangle r(100, 100);
    m_objects.emplace_back(r);
    m_objects[0].add_force({1, 0}, 0.1);
}

void Scene::update()
{
    // update all objects
    for (auto& obj : m_objects)
    {
        obj.update();
    }

    // will be optimized in the future
}

bool Scene::detect_collison(const Transform &obj1, const Transform &obj2)
{
    return true;
}



}