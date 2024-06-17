#include "raylib.h"
#include "shapes.hpp"


namespace pe {

Circle::Circle(const Vec2 pos, const float radius)
    : m_pos(pos), m_radius(radius)
{
}

Rectangle::Rectangle(const float width, const float height)
    : width(width), height(height)
{
}

void Rectangle::draw(const Vec2 pos) const
{
    DrawRectangleLines(pos.x, pos.y, width, height, RED);
}

}
