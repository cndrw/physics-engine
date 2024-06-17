#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include "transform.hpp"
#include "rigidbody.hpp"

namespace pe {

class Scene final
{
public:
    Scene();
    void add_object(const Transform& obj);
    void remove_object(const Transform& obj);
    void clear_scene();
    void update_physics();
    void late_update();
    void update();
    bool detect_collison(const Transform& obj1, const Transform& obj2);

private:
    std::vector<RigidBody> m_objects;
};

}


#endif //SCENE_HPP
