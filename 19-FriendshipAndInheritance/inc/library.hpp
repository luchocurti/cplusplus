/******************************* Include Guard ********************************/
#pragma once

/****************************** Include Headers *******************************/
#include <iostream>

/******************************** Definitions *********************************/

/************** Defines **************/
#define IDENTIFIER replacement

/************ Data Types *************/
class Output
{
public:
    static void print(int i);
};

class Polygon
{
    /* By declaring width and height as "protected" instead of "private", these
    members are also accessible from the derived classes. */
protected:
    int width;
    int height;

public:
    /* Data members */

    /* Constructors */
    Polygon(int a, int b) : width(a), height(b) {}

    /* Destructor */

    /* Overloaded operators */

    /* Functions */
    void set_values(int a, int b)
    {
        width = a;
        height = b;
    }
};

/* Derived classes definitions use the following syntax:

    class derived_class : access_specifiers base_class
    {
        ...
    };

The "access specifier" limits the most accessible level for the members
inherited from the base class:
    - public    => The derived class will inherit all the members with the same
                   levels they had in the base class.
    - protected => All public members of the base class are inherited as
                   protected in the derived class.
    - private   => All the base class members are inherited as private.       */
class Triangle : public Polygon
{
public:
    /* Data members */

    /* Constructors */
    Triangle(int a, int b) : Polygon(a, b) {}

    /* Destructor */

    /* Overloaded operators */

    /* Functions */
    int area()
    {
        return (width * height / 2);
    }
};

class Square
{
    /* A friend class is a class whose members have access to the private or
    protected members of another class. */
    friend class Rectangle;

private:
    int side;

public:
    /* Data members */

    /* Constructors */
    Square(int a) : side(a) {}

    /* Destructor */

    /* Overloaded operators */

    /* Functions */
    int area()
    {
        return (side * side);
    }
};

/* The objects of the class Rectangle contain members inherited from Polygon.
These are: width, height and set_values.                                      */
/* Multiple inheritance:
A class may inherit from more than one class by simply specifying more base
classes, separated by commas, in the list of a class's base classes.          */
class Rectangle : public Polygon, public Output
{
    /* private: */

public:
    /* Data members */

    /* Constructors */
    Rectangle(int a, int b) : Polygon(a, b) {}

    /* Destructor */

    /* Overloaded operators */

    /* Functions */
    int area()
    {
        return (width * height);
    }

    void convert(Square a);

    /******************* Declaration of External Functions ********************/
    /* "duplicate_rectangles" is NOT a member of this class but it can access
    the private and protected members because it is declared as "friend" */
    friend Rectangle duplicate_rectangles(const Rectangle &param);
};

class Mother
{
public:
    Mother()
    {
        std::cout << "Mother:   No parameters" << std::endl;
    }
    Mother(int a)
    {
        std::cout << "Mother:   int " << a << " parameter" << std::endl;
    }
};

/* A publicly derived class inherits access to every member of a base class
except:
    - its constructors and its destructor
    - its assignment operator members (operator=)
    - its friends
    - its private members

Even though access to the default constructors and destructor of the base class
is not inherited as such, they are automatically called by the constructors and
destructor of the derived class.                                              */
class Son : public Mother
{
public:
    Son()
    {
        std::cout << "Son:      No parameters" << std::endl;
    }

    /* Calling a different constructor other than the default of a base class is
    possible, using this syntax:
    derived_constructor(parameters) : base_constructor(parameters)
    {
        ...
    }                                                                         */
    Son(int a) : Mother(a)
    {
        std::cout << "Son:      int " << a << " parameter" << std::endl;
    }
};

class Daughter : public Mother
{
public:
    Daughter() : Mother()
    {
        std::cout << "Daughter: No parameters" << std::endl;
    }
    Daughter(int a)
    {
        std::cout << "Daughter: int " << a << " parameter" << std::endl;
    }
};

/************** Macros ***************/

/********************************* Constants **********************************/
const char TAB = '\t';

/********************** Functions Prototypes Declaration **********************/
Rectangle duplicate_rectangles(const Rectangle &param);

/********************** Functions Templates Declaration ***********************/
