#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include <cstdint>
#include <memory>
#include "transform.hpp"
#include "rigidbody.hpp"
#include "solver.hpp"
#include "arena.hpp"

namespace pe {

    class Scene final
    {
    public:
        Scene();
        void construct_body();
        void construct_body_handler();
        void add_object(RigidBody* const rb);
        void remove_object(const RigidBody& obj);
        void clear_scene();
        void update_physics(float dt);
        void late_update();
        void update();
        bool detect_collison(const Transform& obj1, const Transform& obj2);

    private:
        struct RigidbodyConstructor
        {
            Vec2 first_pos, second_pos;
            uint8_t state = 0;
            bool active_construct = false;

            template<class T> [[nodiscard]]
            RigidBody* init(Arena<T>*  arena) const;
        };

    private:
        std::vector<RigidBody> m_objects;
        Solver m_solver;
        Arena<RigidBody> m_arena;
        RigidBody m_construction_rect;
        RigidbodyConstructor m_constructor;

    };

}


#endif //SCENE_HPP
