#include "scene.hpp"

#include "shapes.hpp"
#include "rigidbody.hpp"

namespace pe {

Scene::Scene()
{
    pe::Rectangle r(50, 50);
    RigidBody rb(r, 50);
    m_objects.push_back(rb);
    m_objects[0].add_force({1, 0}, 50);
}

void Scene::update()
{
    // update all objects

    // will be optimized in the future
}
void Scene::update_physics(const float dt)
{
    for (auto& obj : m_objects)
    {
        obj.update(dt);
    }
}

void Scene::late_update()
{
    for (auto& obj : m_objects)
    {
        obj.draw();
    }
}



bool Scene::detect_collison(const Transform &obj1, const Transform &obj2)
{
    return true;
}



}