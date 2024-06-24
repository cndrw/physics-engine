#include "scene.hpp"

#include <future>
#include <memory>
#include <thread>
#include <chrono>
#include <iostream>

#include "raylib.h"
#include "shapes.hpp"
#include "rigidbody.hpp"
#include "ui_handler.hpp"

using namespace std::chrono_literals;

namespace pe {

    Scene::Scene()
        : m_construction_rect({0, 0}, {0, 0}, 50)
    {
        // pe::Rectangle r(50, 50);
        // RigidBody rb(r, {0, 0}, 50);
        // m_objects.push_back(rb);
        // m_solver.add_force(m_objects[0], {1, 0}, 50);
        // m_solver.add_gravity(m_objects[0]);
    }

    void Scene::update()
    {
        // update all objects
        if (m_constructor.construct)
        {
            construct_body_handler();
        }

        // will be optimized in the future
    }
    void Scene::update_physics(const float dt)
    {
        for (auto& obj : m_objects)
        {
            std::cout << obj.force << std::endl;
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
        std::cout << "added object\n";
        std::cout << rb->curr_tf.pos << std::endl;
        m_solver.add_gravity(*rb);
        std::cout << "with foce " << rb->force << std::endl;
        m_objects.push_back(*rb);
    }

    void Scene::construct_body()
    {
       m_constructor.construct = true;
    }

    void Scene::construct_body_handler()
    {
        m_constructor.construct = true;
        const auto mouse_pressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        switch (m_construct_state)
        {
            case 0:
                m_construct_state++;
                std::cout << "state 0\n";
                break;
            case 1:
                if (mouse_pressed)
                {
                    std::cout << "state 1\n";
                    m_constructor.first_pos = UIHandler::GetMousePos();
                    m_construct_state++;
                }
                break;
            case 2:
                if (mouse_pressed)
                {
                    m_constructor.second_pos = UIHandler::GetMousePos();
                    add_object(m_constructor.init());
                    m_constructor.construct = false;
                    m_construct_state = 0;
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

    std::unique_ptr<RigidBody> Scene::RigidbodyConstructor::init() const
    {
        const auto [width, height] = second_pos - first_pos;
        Rectangle rect(width, height);
        return std::make_unique<RigidBody>(rect, first_pos, 50);
    }


}