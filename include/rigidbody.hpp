#ifndef RIGIDBODY_HPP
#define RIGIDBODY_HPP

#include "transform.hpp"
#include "shapes.hpp"

namespace pe {

struct RigidBody
{
    RigidBody(Rectangle shape, float mass);

    Rectangle shape;
    Transform curr_tf{};
    Transform last_tf{};
    Vec2 force;
    float mass;
};

}

#endif //RIGIDBODY_HPP
