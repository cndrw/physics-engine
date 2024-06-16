#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <cstdint>

namespace pe {

struct Vec2
{
    float x = 0, y = 0;

    [[nodiscard]]
    Vec2 normalized() const;
    Vec2& operator*(float val);
    Vec2& operator+=(const Vec2& other);
};

struct AABB // Alix Aligned Bounding Box
{
    Vec2 min;
    Vec2 max;
};

struct Transform
{
public:
    Vec2 pos = {0, 0};

private:
    AABB m_bbox;
    int16_t m_angle = 0; // 0° is to the rigth

public:
    Transform& operator+=(const Transform& other);
};

}; // pe

#endif //TRANSFORM_H
