#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <cstdint>
#include <fstream>
#include <ostream>

namespace pe {

struct Vec2
{
    float x = 0, y = 0;

    [[nodiscard]]
    Vec2 normalized() const;
    [[nodiscard]]
    float len() const;
    [[nodiscard]]
    static float distance(Vec2 v1, Vec2 v2);
    [[nodiscard]]
    static float dot(Vec2 v1, Vec2 v2);
    Vec2 operator*(float val) const;
    Vec2& operator+=(const Vec2& other);
    Vec2& operator-=(float val);
    Vec2& operator-=(const Vec2& other);
    Vec2 operator/(float val) const;
    Vec2 operator+(const Vec2& other) const;
    Vec2 operator-(const Vec2& rhs) const;
    Vec2 operator-(Vec2&& rhs) const;
    Vec2 operator-() const;
    friend std::ostream& operator<<(std::ostream& stream, const Vec2& v);

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
