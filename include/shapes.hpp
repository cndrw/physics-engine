#ifndef SHAPES_H
#define SHAPES_H

#include "transform.hpp"

namespace pe {

class Circle : public Transform
{
public:
    Circle(Vec2 pos, float radius);

private:
    Vec2 m_pos;
    float m_radius;
};

class Rectangle
{
public:
    float width, height;

public:
    Rectangle(float width, float height);
    void draw(Vec2 pos) const;
};
};

#endif //SHAPES_H
