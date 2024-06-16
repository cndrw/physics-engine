#include "transform.hpp"

#include <valarray>


namespace pe {

Vec2& Vec2::operator+=(const Vec2& other)
{
    this->x += other.x;
    this->y += other.y;
    return *this;
}

Vec2& Vec2::operator*(const float val)
{
    this->x *= val;
    this->x *= val;
    return *this;
}

[[nodiscard]]
Vec2 Vec2::normalized() const
{
    const auto len = static_cast<float>(std::sqrt(x*x + y*y));
    return {x / len, y / len};
}


}
