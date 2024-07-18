#include "solver.hpp"
#include <iostream>

namespace pe {

    void Solver::add_gravity(RigidBody& rb) const
    {
        rb.force.y += EARTH_GRAVITY_CONST / rb.inv_mass;
    }

    void Solver::add_force(RigidBody& rb, const Vec2 dir, const float strength) const
    {
        rb.force += dir.normalized() * strength;
    }

    void Solver::update(RigidBody& rb, const float dt) const
    {
        // kif (dt >= 0.02) return;

        // equation from 2 times deriving F = m * a and x = x_0 + v_0 * t + 0.5 * a * t^2
        // std::cout << rb.inv_mass << std::endl;
        const Vec2 traveled_way = rb.velocity + ((rb.force + rb.impulse) * rb.inv_mass / 2) * dt * dt;

        rb.velocity = (rb.curr_tf.pos - rb.last_tf.pos) / METER_TO_PIXEL;
        rb.last_tf.pos = rb.curr_tf.pos;
        move(rb, traveled_way);

        rb.impulse = rb.impulse.len() > 0 ? rb.impulse - Vec2{10, 10} : Vec2{0, 0};
        if (rb.curr_tf.pos.y + rb.shape.height > FLOOR)
        {
            rb.curr_tf.pos.y = FLOOR - rb.shape.height;
        }
    }

    void Solver::handle_collision(std::vector<RigidBody>& rbs) const
    {
        for (auto& rb1 : rbs)
        {
            for (auto& rb2 : rbs)
            {
                if (&rb1 == &rb2) continue;

                if (is_colliding(rb1, rb2))
                {
                    resolve_collision(rb1, rb2);
                }
            }
        }
    }

    bool Solver::is_colliding(const RigidBody& rb1, const RigidBody& rb2) const
    {
        const Vec2 pos1 = rb1.curr_tf.pos;
        const Vec2 pos2 = rb2.curr_tf.pos;
        const bool horizontal_collision = (pos2.x > pos1.x && pos2.x < pos1.x + rb1.shape.width) ||
                                          (pos1.x > pos2.x && pos1.x < pos2.x + rb2.shape.width);

        const bool vertical_collision = (pos2.y > pos1.y && pos2.y < pos1.y + rb1.shape.height) ||
                                          (pos1.y > pos2.y && pos1.y < pos2.y + rb2.shape.height);
        return horizontal_collision && vertical_collision;
    }

    void Solver::resolve_collision(RigidBody& rb1, RigidBody& rb2) const
    {
        const Vec2 normal = (rb2.curr_tf.pos - rb1.curr_tf.pos).normalized();
        const Vec2 rel_vel = rb2.velocity - rb1.velocity;

        float vel_normal = Vec2::dot(rel_vel, normal);

        if (vel_normal > 0) return;

        float j = -vel_normal;
        j /= rb1.inv_mass + rb2.inv_mass;
        const Vec2 impulse = normal * j;

        float mass_sum = rb1.inv_mass + rb2.inv_mass;

        float ratio = rb1.inv_mass / mass_sum;
        rb1.velocity -= impulse * ratio;

        ratio = rb2.inv_mass / mass_sum;
        rb2.velocity += impulse * ratio;
    }

    void Solver::add_impulse(RigidBody& rb, const Vec2 dir, const float strength) const
    {
        rb.impulse += dir.normalized() * strength;
    }

    void Solver::move(RigidBody& rb, const Vec2 dir) const
    {
        rb.curr_tf.pos += dir * METER_TO_PIXEL;
    }

}