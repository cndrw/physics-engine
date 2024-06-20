#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include "transform.hpp"
#include "rigidbody.hpp"
#include "solver.hpp"
#include <memory>

namespace pe {

class Scene final
{
public:
    Scene();
    void add_object(const std::shared_ptr<RigidBody>& rb);
    void remove_object(const RigidBody& obj);
    void clear_scene();
    void update_physics(float dt);
    void late_update();
    void update();
    bool detect_collison(const Transform& obj1, const Transform& obj2);

private:
    std::vector<RigidBody> m_objects;
    Solver m_solver;
};

}


#endif //SCENE_HPP
