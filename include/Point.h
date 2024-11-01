#pragma once

#include <iostream>

class Point
{   
    public:
        Point();
        Point(double x, double y);
        Point(const Point &other);

        Point &operator = (const Point &other);
        Point &operator = (Point &&other);

        Point operator + (const Point &other) const;
        Point operator - (const Point &other) const;
        bool operator == (const Point &other) const;

        double getX() const {return x;}
        double getY() const {return y;}

        friend std::ostream& operator<<(std::ostream& os, const Point& point);
        friend std::istream& operator>>(std::istream& is, Point& point);

        double x, y; 
};