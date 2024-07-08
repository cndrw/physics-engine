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

    Vec2 &Vec2::operator-=(const Vec2& other)
    {
        this->x -= other.x;
        this->y -= other.y;
        return *this;
    }

    Vec2& Vec2::operator-=(const float val)
    {
        this->x -= val;
        this->y -= val;
        return *this;
    }

    Vec2 Vec2::operator-() const
    {
       return {-this->x, -this->y};
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

    Vec2 Vec2::operator-(Vec2&& rhs) const
    {
        Vec2 res = *this;
        res.x -= rhs.x;
        res.y -= rhs.y;
        return res;
    }

    std::ostream& operator<<(std::ostream& stream, const Vec2& v)
    {
        stream << "x: " << v.x << " y: " << v.y << " ";
        return stream;
    }

    [[nodiscard]]
    float Vec2::distance(const Vec2 v1, const Vec2 v2)
    {
        const Vec2 v_distance  = v2 - v1;
        return v_distance.len();
    }

    [[nodiscard]]
    Vec2 Vec2::normalized() const
    {
        const auto l = len();
        return {x / l, y / l};
    }

    [[nodiscard]]
    float Vec2::len() const
    {
        return std::sqrt(x * x + y * y);
    }

    [[nodiscard]]
    float Vec2::dot(const Vec2 v1, const Vec2 v2)
    {
        return v1.x * v2.x + v1.y * v2.y;
    }

}
