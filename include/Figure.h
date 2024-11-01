#pragma once

#include <iostream>
#include "Point.h"

class Figure
{
    public:
        virtual Point center() const = 0;
        virtual double area() const = 0;
        virtual operator double() const = 0;  

        virtual ~Figure() {}
        
        virtual std::ostream& print(std::ostream& os)const{
            return os;
        }
        virtual std::istream& input(std::istream& is){
            return is;
        }
};