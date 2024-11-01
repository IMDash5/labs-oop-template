#include "../include/Point.h"

Point::Point() : x{0}, y{0} {}
Point::Point(double x, double y): x{x}, y{y} {}
Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point& Point::operator=(const Point& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

Point& Point::operator=(Point&& other) {
    x = other.x;
    y = other.y;

    return *this;
}


Point Point::operator + (const Point &other) const{
    return Point(x + other.x, y + other.y);
}

Point Point::operator - (const Point &other) const{
    return Point(x - other.x, y - other.y);
}

bool Point::operator == (const Point &other) const{
    return (x == other.x) && (y == other.y);
}

std::istream &operator>>(std::istream &is, Point &point){
    double x, y;
    is >> x >> y;
    point.x = x;
    point.y = y;

    return is;
}

std::ostream &operator<<(std::ostream &os, const Point &point){
    os << "(" << point.x << "; " << point.y << ")";
    
    return os;
}