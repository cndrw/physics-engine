#include <iostream>
#include "raylib.h"
#include "rigidbody.hpp"

#include <valarray>

#include "shapes.hpp"
#include "transform.hpp"


namespace pe {

constexpr double EARTH_GRAVITY_CONST {std::pow(9.870778, -28)};

RigidBody::RigidBody(const Rectangle& rect, const float mass)
    : m_shape(rect), m_mass(mass)
{
    std::cout << "hi" << std::endl;
    add_gravity();
}

void RigidBody::add_force(const Vec2 dir, const float strength)
{
    m_force = dir.normalized() * strength;
}

void RigidBody::add_gravity()
{
    Vec2 gravity_force;
    gravity_force.y = EARTH_GRAVITY_CONST * m_mass;
    std::cout << gravity_force.y << std::endl;
    m_force += gravity_force;
}

void RigidBody::update()
{
    move(m_force);
    // std::cout << pos.x << " " << pos.y << std::endl;
}

void RigidBody::draw() const
{
    m_shape.draw(pos);
}


}

