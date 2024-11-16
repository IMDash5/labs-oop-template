#pragma once

#include <iostream>
#include <concepts>

template <typename T>
concept isScalar = std::is_arithmetic_v<T>;

template <isScalar T>
class Point
{   
    public:
        Point();
        Point(T x ,T y);
        Point(const Point &other);

        Point &operator = (const Point &other);
        Point &operator = (Point &&other);

        Point operator + (const Point &other) const;
        Point operator - (const Point &other) const;
        bool operator == (const Point &other) const;

        T getX() const {return x;}
        T getY() const {return y;}

        friend std::ostream& operator<<(std::ostream& os, const Point& point) {
            os << "(" << point.x << ", " << point.y << ")";
            return os;
        }

        friend std::istream& operator>>(std::istream& is, Point& point) {
            is >> point.x >> point.y;
            return is;
        }

        T x, y; 
};