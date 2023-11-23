/****************************** Include Headers *******************************/
#include "library.hpp"

/**************************** Function Definitions ****************************/
/* The duplicate_rectangles function is a "friend" of class Rectangle.
It is NOT a member of class Rectangle, but it has access to its private and
protected members.
Typical use cases of friend functions are operations that are conducted between
two different classes accessing private members of both. */
Rectangle duplicate_rectangles(const Rectangle &param)
{
    Rectangle result(0, 0);

    result.width = param.width * 2;
    result.height = param.height * 2;

    return result;
}

void Rectangle::convert(Square a)
{
    width = a.side;
    height = a.side;

    return;
}

void Output::print(int i)
{
    std::cout << "Output::print = " << i << std::endl;
}
