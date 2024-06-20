#include "solver.hpp"

namespace pe {

void Solver::add_gravity(RigidBody& rb) const
{
    rb.force.y += EARTH_GRAVITY_CONST * rb.mass;
}

void Solver::add_force(RigidBody& rb, const Vec2 dir, const float strength) const
{
    rb.force += dir.normalized() * strength;
}

void Solver::update(RigidBody& rb, const float dt) const
{
    if (dt >= 0.02) return;

    // equation from 2 times deriving F = m * a and x = x_0 + v_0 * t + 0.5 * a * t^2
    const Vec2 velocity = (rb.curr_tf.pos - rb.last_tf.pos) / METER_TO_PIXEL;
    const Vec2 traveled_way =  velocity + (rb.force / rb.mass / 2) * dt * dt;

    rb.last_tf.pos = rb.curr_tf.pos;
    move(rb, traveled_way);

    if (rb.curr_tf.pos.y + rb.shape.height > FLOOR)
    {
        rb.curr_tf.pos.y = FLOOR - rb.shape.height;
    }

}

void Solver::move(RigidBody& rb, const Vec2 dir) const
{
    rb.curr_tf.pos += dir * METER_TO_PIXEL;
}




}