#include <iostream>
#include "raylib.h"
#include "rigidbody.hpp"

#include <valarray>

#include "shapes.hpp"
#include "transform.hpp"

#define PRINTVEC(v) std::cout << v.x << " " << v.y << std::endl;

namespace pe {

constexpr float EARTH_GRAVITY_CONST {9.91};
constexpr int METER_TO_PIXEL {100};
constexpr int FLOOR {400};


RigidBody::RigidBody(const Rectangle& rect, const float mass)
    : m_shape(rect), m_mass(mass)
{
    add_gravity();
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

    // equation from 2 times deriving F = m * a and x = x_0 + v_0 * t + 0.5 * a * t^2
    const Vec2 velocity = (curr_tf.pos - last_tf.pos) / METER_TO_PIXEL;
    const Vec2 traveled_way =  velocity + (m_force / m_mass / 2) * dt * dt;

    last_tf.pos = curr_tf.pos;
    move(traveled_way);

    if (curr_tf.pos.y + m_shape.height > FLOOR)
    {
        curr_tf.pos.y = FLOOR - m_shape.height;
    }
}

void RigidBody::move(const Vec2 dir)
{
    curr_tf.pos += dir * METER_TO_PIXEL;
}

void RigidBody::draw() const
{
    m_shape.draw(curr_tf.pos);
}


}

