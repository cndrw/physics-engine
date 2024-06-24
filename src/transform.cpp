#include "transform.hpp"

#include <stdexcept>
#include <valarray>


namespace pe {

    Vec2& Vec2::operator+=(const Vec2& other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    Vec2 Vec2::operator/( const float val) const
    {
        if (val == 0)
        {
            throw std::invalid_argument("Can't divide Vec2 by zero.");
        }

        Vec2 res = *this;
        res.x /= val;
        res.y /= val;
        return res;
    }

    Vec2 Vec2::operator*(const float val) const
    {
        Vec2 res = *this;
        res.x *= val;
        res.y *= val;
        return res;
    }

    Vec2 Vec2::operator+(const Vec2& other) const
    {
        Vec2 res = *this;
        res.x += other.x;
        res.y += other.y;
        return res;
    }

    Vec2 Vec2::operator-(const Vec2& other) const
    {
        Vec2 res = *this;
        res.x -= other.x;
        res.y -= other.y;
        return res;
    }

    std::ostream& operator<<(std::ostream& stream, const Vec2& v)
    {
        stream << "x: " << v.x << " y: " << v.y << " ";
        return stream;
    }

    float Vec2::distance(const Vec2 v1, const Vec2 v2)
    {
        const Vec2 v_distance  = v2 - v1;
        return std::sqrt(v_distance.x * v_distance.x + v_distance.y * v_distance.y);
    }



[[nodiscard]]
Vec2 Vec2::normalized() const
{
    const auto len = static_cast<float>(std::sqrt(x*x + y*y));
    return {x / len, y / len};
}


}
