#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "transform.hpp"
#include "rigidbody.hpp"

namespace pe {

    class Solver
    {
    public:
        void move(RigidBody& rb, Vec2 dir) const;
        void update(RigidBody& rb, float dt) const;
        void add_impulse(RigidBody& rb, Vec2 dir, float strength) const;
        void add_force(RigidBody& rb, Vec2 dir, float strength) const;
        void add_gravity(RigidBody& rb) const;

    private:
        const float EARTH_GRAVITY_CONST {9.91};
        const float METER_TO_PIXEL {100};
        const float FLOOR {400};
    };
}

#endif //SOLVER_HPP
