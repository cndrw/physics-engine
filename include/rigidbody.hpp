#ifndef RIGIDBODY_HPP
#define RIGIDBODY_HPP

#include "transform.hpp"
#include "shapes.hpp"

namespace pe {

class RigidBody
{
public:
    RigidBody(const Rectangle& rect, float mass);
    void move(Vec2 dir);
    void update(float dt);
    void add_force(Vec2 dir, float strength);
    void add_impulse(Vec2 dir, float stength);
    void draw() const;

private:
    void add_gravity();

private:
    Rectangle m_shape;
    Transform curr_tf{};
    Transform last_tf{};
    Vec2 m_force;
    float m_mass;
};

}

#endif //RIGIDBODY_HPP
