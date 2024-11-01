#include <iostream>
#include <cmath>

#include "../include/Triangle.h"

Triangle::Triangle() : a(Point()), b(Point()), c(Point()) {}
Triangle::Triangle(Point& p1, Point& p2, Point& p3) : a(p1), b(p2), c(p3) {}

Triangle& Triangle::operator=(const Triangle &other) {
    if (this != &other) {
        a = other.a;
        b = other.b;
        c = other.c;
    }
    return *this;
}

Triangle& Triangle::operator=(Triangle &&other) noexcept {
    if (this != &other) {
        a = std::move(other.a);
        b = std::move(other.b);
        c = std::move(other.c);
    }
    return *this;
}


bool Triangle::operator==(const Triangle &other) {
    return (a == other.a) && (b == other.b) && (c == other.c);
}

double Triangle::area() const {
    double ab = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
    double ac = sqrt(pow(c.x - a.x, 2) + pow(c.y - a.y, 2));
    double bc = sqrt(pow(c.x - b.x, 2) + pow(c.y - b.y, 2));
    
    double s = (ab + ac + bc) / 2;
    return sqrt(s * (s - ab) * (s - ac) * (s - bc));
}

Triangle::operator double() const {
    return area(); 
}
Point Triangle::center() const {
    double centerX = (a.x + b.x + c.x) / 3;
    double centerY = (a.y + b.y + c.y) / 3;
    return Point(centerX, centerY);
}

std::ostream& Triangle::print(std::ostream& os)const {
    os << "Вершины треугольника: " << a << ", " << b << ", " << c;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Triangle& triangle) {
    return triangle.print(os);
}

std::istream& Triangle::input(std::istream& is) {
    return is >> *this; 
}

std::istream& operator>>(std::istream& is, Triangle& triangle) {
    std::cout << "Введите координаты для вершины А (x, y): ";
    is >> triangle.a;
    std::cout << "Введите координаты для вершины B (x, y): ";
    is >> triangle.b;
    std::cout << "Введите координаты для вершины C (x, y): ";
    is >> triangle.c;
    return is;
}