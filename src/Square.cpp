#include <iostream>
#include <cmath>

#include "../include/Square.h"

Square::Square() : a(Point()), b(Point()), c(Point()), d(Point()) {}    
Square::Square(Point& p1, Point& p2, Point& p3, Point& p4) : a(p1), b(p2), c(p3), d(p4) {}

Square& Square::operator=(const Square &other) {
    if (this != &other) {
        a = other.a;
        b = other.b;
        c = other.c;
        d = other.d;
    }
    return *this;
}

Square& Square::operator=(Square &&other) {
    a = other.a;
    b = other.b;
    c = other.c;
    d = other.d;

    return *this;
}

bool Square::operator==(const Square &other) {
    return (a == other.a) && (b == other.b) && (c == other.c) && (d == other.d);
}

double Square::area() const {
    double side = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
    return side * side;
}

Square::operator double() const {
    return area(); 
}


Point Square::center() const {
    double centerX = (a.x + b.x + c.x + d.x) / 4;
    double centerY = (a.y + b.y + c.y + d.y) / 4;
    return Point(centerX, centerY);
}

std::ostream& Square::print(std::ostream& os) const {
    os << "Square vertices: " << a << ", " << b << ", " << c << ", " << d;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Square& square) {
    return square.print(os);
}

std::istream& Square::input(std::istream& is) {
    return is >> *this; 
}

std::istream& operator>>(std::istream& is, Square& square) {
    std::cout << "Введите координаты для вершины А (x, y): ";
    is >> square.a;
    std::cout << "Введите координаты для вершины B (x, y): ";
    is >> square.b;
    std::cout << "Введите координаты для вершины C (x, y): ";
    is >> square.c;
    std::cout << "Введите координаты для вершины D (x, y): ";
    is >> square.d;
    return is;
}