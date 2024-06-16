#ifndef RIGIDBODY_HPP
#define RIGIDBODY_HPP

#include "transform.hpp"
#include "shapes.hpp"

namespace pe {

class RigidBody : public Transform
{
public:
    explicit RigidBody(const Rectangle& rect);
    void move(const Vec2 dir) { pos += dir; };
    void update();
    void add_force(Vec2 dir, float strength);
    void add_impulse(Vec2 dir, float stength);

private:
    Rectangle m_shape;
    Vec2 m_force;
};

}

#endif //RIGIDBODY_HPP
