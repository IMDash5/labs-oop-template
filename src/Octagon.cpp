#include <iostream>
#include <cmath>

#include "../include/Octagon.h"

Octagon::Octagon() : a(Point()), b(Point()), c(Point()), d(Point()), e(Point()), f(Point()), g(Point()), h(Point()) {}
Octagon::Octagon(Point& p1, Point& p2, Point& p3, Point& p4, Point& p5, Point& p6, Point& p7, Point& p8) : a(p1), b(p2), c(p3), d(p4), e(p5), f(p6), g(p7), h(p8){}

Octagon& Octagon::operator=(const Octagon &other) {
    if (this != &other) {
        a = other.a;
        b = other.b;
        c = other.c;
        d = other.d;
        e = other.e;
        f = other.f;
        g = other.g;
        h = other.h;
    }
    return *this;
}

Octagon& Octagon::operator=(Octagon &&other) {
    a = other.a;
    b = other.b;
    c = other.c;
    d = other.d;
    e = other.e;
    f = other.f;
    g = other.g;
    h = other.h;

    return *this;
}

bool Octagon::operator==(const Octagon &other) {
    return (a == other.a) && (b == other.b) && (c == other.c) && (d == other.d) && (e == other.e) && (f == other.f) && (g == other.g) && (h == other.h);
}

double Octagon::area() const {
    double area = 0.0;
    Point points[8] = { a, b, c, d, e, f, g, h };

    for (int i = 0; i < 8; i++) {
        int j = (i + 1) % 8;
        area += points[i].x * points[j].y;
        area -= points[i].y * points[j].x;
    }
    return std::fabs(area) / 2.0;
}

Octagon::operator double() const {
    return area(); 
}

Point Octagon::center() const {
    double centerX = (a.x + b.x + c.x + d.x + e.x + f.x + g.x + h.x) / 8.0;
    double centerY = (a.y + b.y + c.y + d.y + e.y + f.y + g.y + h.y) / 8.0;
    return Point(centerX, centerY);
}

std::ostream& Octagon::print(std::ostream& os) const {
    os << "Вершины восьмиугольника: " << a << ", " << b << ", " << c << ", " << d << ", " << e << ", " << f << ", " << g << ", " << h;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Octagon& octagon) {
    return octagon.print(os);
}

std::istream& Octagon::input(std::istream& is) {
    return is >> *this; 
}

std::istream& operator>>(std::istream& is, Octagon& octagon) {
    std::cout << "Введите координаты для вершины А (x, y): ";
    is >> octagon.a;
    std::cout << "Введите координаты для вершины B (x, y): ";
    is >> octagon.b;
    std::cout << "Введите координаты для вершины C (x, y): ";
    is >> octagon.c;
    std::cout << "Введите координаты для вершины D (x, y): ";
    is >> octagon.d;
    std::cout << "Введите координаты для вершины E (x, y): ";
    is >> octagon.e;
    std::cout << "Введите координаты для вершины F (x, y): ";
    is >> octagon.f;
    std::cout << "Введите координаты для вершины G (x, y): ";
    is >> octagon.g;
    std::cout << "Введите координаты для вершины H (x, y): ";
    is >> octagon.h;
    return is;
}