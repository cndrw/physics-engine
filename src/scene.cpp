#include "scene.hpp"

#include <future>
#include <memory>
#include <thread>
#include <chrono>
#include <iostream>

#include "raylib.h"
#include "shapes.hpp"
#include "rigidbody.hpp"

using namespace std::chrono_literals;

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
        std::cout << "obj addeca\n";
        m_solver.add_gravity(*rb);
        m_objects.push_back(*rb);
    }

    void Scene::construct_shape()
    {
        auto f = std::async([&]()
        {
            Vector2 first_click, second_click;
            while (true)
            {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                {
                    std::cout << "first click\n";
                    first_click = GetMousePosition();
                    break;
                }
                std::this_thread::sleep_for(0.1s);
            }

            std::this_thread::sleep_for(1s);

            while (true)
            {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                {
                    std::cout << "second click\n";
                    second_click = GetMousePosition();
                    break;
                }
                std::this_thread::sleep_for(0.1s);
            }

            float width = std::abs(second_click.x - first_click.x);
            float height = std::abs(second_click.y - first_click.y);
            Rectangle r(width, height);
            auto rb = std::make_shared<RigidBody>(r, 50);
            rb->curr_tf.pos.x = first_click.x;
            rb->curr_tf.pos.y = first_click.y;
            add_object(rb);
        });
    }


    bool Scene::detect_collison(const Transform &obj1, const Transform &obj2)
    {
        return true;
    }

}