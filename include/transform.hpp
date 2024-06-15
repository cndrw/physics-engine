#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <cstdint>

namespace pe {

struct Vec2
{
    int16_t x = 0, y = 0;
};

struct AABB // Alix Aligned Bounding Box
{
    Vec2 min;
    Vec2 max;
};

struct Transform
{
    public:
    Vec2 pos;

    private:
    AABB m_bbox;
    int16_t m_angle = 0; // 0° is to the rigth
};

}; // pe

#endif //TRANSFORM_H
