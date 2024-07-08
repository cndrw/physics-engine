#ifndef RIGIDBODY_HPP
#define RIGIDBODY_HPP

#include "transform.hpp"
#include "shapes.hpp"

namespace pe {

struct RigidBody
{
    RigidBody(Rectangle shape, Vec2 pos, float mass);

    Rectangle shape;
    Transform curr_tf{};
    Transform last_tf{};
    Vec2 velocity;
    Vec2 force;
    Vec2 impulse;
    float mass;
};

}

#endif //RIGIDBODY_HPP
