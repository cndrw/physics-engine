#include <iostream>
#include "raylib.h"
#include "rigidbody.hpp"
#include "shapes.hpp"
#include "transform.hpp"


namespace pe {

RigidBody::RigidBody(const Rectangle &rect)
    : m_shape(rect)
{
}

void RigidBody::add_force(const Vec2 dir, const float strength)
{
    m_force = dir.normalized() * strength;
}


void RigidBody::update()
{
    move(m_force);
    // std::cout << pos.x << " " << pos.y << std::endl;
    DrawRectangleLines(pos.x, pos.y, m_shape.width, m_shape.height, RED);
}

}

