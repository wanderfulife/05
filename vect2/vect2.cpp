#include "vect2.hpp"

vect2::vect2()
{
    this->x = 0;
    this->y = 0;
}

vect2::vect2(int num1, int num2)
{
    this->x = num1;
    this->y = num2;
}

vect2::vect2(const vect2& source)
{
    *this = source;
}