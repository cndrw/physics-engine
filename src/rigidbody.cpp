#include <iostream>
#include "raylib.h"
#include "rigidbody.hpp"

#include <valarray>

#include "shapes.hpp"
#include "transform.hpp"


namespace pe {

constexpr float EARTH_GRAVITY_CONST {9.91};
constexpr int METER_TO_PIXEL {100};


RigidBody::RigidBody(const Rectangle& rect, const float mass)
    : m_shape(rect), m_mass(mass)
{
    // add_gravity();
}

void RigidBody::add_force(const Vec2 dir, const float strength)
{
    m_force += dir.normalized() * strength;
}

void RigidBody::add_gravity()
{
    m_force.y += EARTH_GRAVITY_CONST * m_mass;
}

void RigidBody::update(const float dt)
{
    if (dt >= 0.02) return;
    // equation from 2 times deriving F = m * a
    std::cout << dt << std::endl;
    const Vec2 traveled_way = (m_force / m_mass) * dt*dt;
    move(traveled_way);
    std::cout << traveled_way.x << " " << traveled_way.y << std::endl;

}

void RigidBody::move(const Vec2 dir)
{
    pos += dir * METER_TO_PIXEL;
}

void RigidBody::draw() const
{
    m_shape.draw(pos);
}


}

