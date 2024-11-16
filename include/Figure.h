#pragma once

#include <iostream>
#include "Point.h"

template <isScalar T>
class Figure
{
    public:
        virtual Point<T> center() const = 0;
        virtual double area() const = 0;
        virtual operator double() const = 0;  

        virtual ~Figure() {}    
};