#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <vector>

#include "transform.hpp"
#include "rigidbody.hpp"

namespace pe {

    class Solver
    {
    public:
        void move(RigidBody& rb, Vec2 dir) const;
        void update(RigidBody& rb, float dt) const;
        void handle_collision(std::vector<RigidBody>& rbs) const;
        void add_impulse(RigidBody& rb, Vec2 dir, float strength) const;
        void add_force(RigidBody& rb, Vec2 dir, float strength) const;
        void add_gravity(RigidBody& rb) const;

    private:
        bool is_colliding(const RigidBody& rb1, const RigidBody& rb2) const;
        void resolve_collision(RigidBody& rb1, RigidBody& rb2) const;
        void positional_correction(RigidBody& rb1, RigidBody& rb2, Vec2 normal) const;

    private:
        const float EARTH_GRAVITY_CONST {9.91};
        const float METER_TO_PIXEL {100};
        const float FLOOR {400};
    };
}

#endif //SOLVER_HPP
