#include "scene.hpp"

#include <memory>

#include "shapes.hpp"
#include "rigidbody.hpp"

namespace pe {

Scene::Scene()
{
    pe::Rectangle r(50, 50);
    RigidBody rb(r, 50);
    m_objects.push_back(rb);
    m_solver.add_force(m_objects[0], {1, 0}, 50);
    m_solver.add_gravity(m_objects[0]);
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
        m_solver.update(obj, dt);
    }
}

void Scene::late_update()
{
    for (const auto& obj : m_objects)
    {
        obj.shape.draw(obj.curr_tf.pos);
    }
}

void Scene::add_object(const std::shared_ptr<RigidBody>& rb)
{
    m_solver.add_gravity(*rb);
    m_objects.push_back(*rb);
}


bool Scene::detect_collison(const Transform &obj1, const Transform &obj2)
{
    return true;
}



}