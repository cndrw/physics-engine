#include "scene.hpp"

#include <future>
#include <memory>
#include <thread>
#include <chrono>
#include <engine.hpp>
#include <iostream>

#include "raylib.h"
#include "shapes.hpp"
#include "rigidbody.hpp"
#include "ui_handler.hpp"
#include "arena.hpp"

using namespace std::chrono_literals;

namespace pe {

    constexpr auto MB {1024 * 1024};

    Scene::Scene()
        : m_arena(10 * MB), m_construction_rect({0, 0}, {0, 0}, 50)
    {
        // pe::Rectangle r(50, 50);
        // RigidBody rb(r, {0, 0}, 50);
        // m_objects.push_back(rb);
        // m_solver.add_force(m_objects[0], {1, 0}, 50);
        // m_solver.add_gravity(m_objects[0]);
    }

    void Scene::update(const float dt)
    {
        // update all objects
        if (m_constructor.active_construct)
        {
            construct_body_handler();
        }

        for (auto& obj : m_objects)
        {
            m_solver.update(obj, dt);
        }

        m_solver.handle_collision(m_objects);

        // will be optimized in the future
    }

    void Scene::late_update()
    {
        for (const auto& obj : m_objects)
        {
            obj.shape.draw(obj.curr_tf.pos);
        }
    }

    void Scene::add_object(RigidBody* const rb)
    {
        std::cout << "added object\n";
        std::cout << rb->curr_tf.pos << std::endl;
        m_solver.add_gravity(*rb);
        std::cout << "with foce " << rb->force << std::endl;
        m_objects.push_back(*rb);
    }

    void Scene::construct_body()
    {
       m_constructor.active_construct = true;
    }

    void Scene::construct_body_handler()
    {
        switch (m_constructor.state)
        {
            case 0:
                m_constructor.state++;
                break;
            case 1:
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                {
                    m_constructor.first_pos = UIHandler::GetMousePos();
                    m_constructor.state++;
                }
                break;
            case 2:
                if (IsMouseButtonUp(MOUSE_BUTTON_LEFT))
                {
                    m_constructor.second_pos = UIHandler::GetMousePos();
                    add_object(m_constructor.init(&m_arena));
                    m_constructor.active_construct = false;
                    m_constructor.state = 0;
                }
                else
                {
                    const auto [x, y] = m_constructor.first_pos;
                    const auto [width, height] = UIHandler::GetMousePos() - m_constructor.first_pos;
                    DrawRectangleLines(x, y, width, height, RED);
                }
                break;
            default:
                break;
        }
    }


    bool Scene::detect_collison(const Transform &obj1, const Transform &obj2)
    {
        return true;
    }

    RigidBody* Scene::RigidbodyConstructor::init(Arena* arena) const
    {
        const auto [width, height] = second_pos - first_pos;
        const float mass = width * height / 100;
        const Rectangle rect(width, height);
        auto* rb = static_cast<RigidBody*>(arena->push(sizeof(RigidBody)));
        rb->shape = rect;
        rb->curr_tf.pos = first_pos;
        rb->last_tf.pos = first_pos;
        rb->inv_mass = 1.0 / mass;
        return rb;
    }


}