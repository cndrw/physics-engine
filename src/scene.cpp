#include "scene.hpp"
#include <iostream>
#include "shapes.hpp"

namespace pe {

Scene::Scene()
{
    m_objects.push_back(Circle({10, 10} ,4));
}

void Scene::update()
{
    // will be optimized in the future
    for (auto& first : m_objects)
    {
        first.pos.x++;
        for (auto& second : m_objects)
        {
            if(detect_collison(first, second))
            {
                std::cout << "Objects colliding\n";
                first.pos.x--;
            }
        }
    }
}

bool Scene::detect_collison(const Transform &obj1, const Transform &obj2)
{
    return true;
}



}