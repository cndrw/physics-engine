#include <iostream>
#include "raylib.h"
#include "rigidbody.hpp"

#include <valarray>

#include "shapes.hpp"
#include "transform.hpp"

#define PRINTVEC(v) std::cout << v.x << " " << v.y << std::endl;


namespace pe {

    RigidBody::RigidBody(const Rectangle shape, const Vec2 pos, const float mass)
        : shape(shape), mass(mass)
    {
        curr_tf.pos = pos;
        last_tf.pos = pos;
    }

}

