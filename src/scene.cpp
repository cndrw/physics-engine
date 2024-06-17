#include "scene.hpp"

#include "shapes.hpp"
#include "rigidbody.hpp"

namespace pe {

Scene::Scene()
{
    pe::Rectangle r(100, 100);
    RigidBody rb(r, 50);
    m_objects.push_back(rb);
    m_objects[0].add_force({1, 0}, 0.1);
}

void Scene::update()
{
    // update all objects

    // will be optimized in the future
    for (auto& obj : m_objects)
    {
        obj.update();
    }
}
void Scene::update_physics()
{
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