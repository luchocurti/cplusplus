/****************************** Include Headers *******************************/
#include <iostream>
#include <string>
#include <sstream>
#include <array>
#include <new>

/********************************* Namespaces *********************************/

/******************************** Definitions *********************************/
/************** Defines **************/
#define IDENTIFIER replacement

/************ Data Types *************/
/* Classes can be defined not only with keyword "class", but also with keywords
"struct" and "union". */
class Rectangle /* Class Declaration */
{
/* private: */
    int width; /* Data members */
    int height;
    int depth;

public:
    Rectangle();         /* The default constructor */
    Rectangle(int, int); /* Overloaded constructor */
    Rectangle(int, int, int);
    void set_values(int, int); /* Function members */
    int get_area(void)         /* Automatically considered an inline function */
    {
        return (width * height);
    }
};

class Circle
{
/* private: */
    double radius;

public:
    Circle() /* Default constructor */
    {
        radius = 5.0;
    }
    Circle(double r)
    {
        radius = r;
    }
    double circumference()
    {
        return (2.0 * 3.14159265 * radius);
    }
    double area()
    {
        return (3.14159265 * radius * radius);
    }
};

class Cylinder
{
/* private: */
    Circle base;
    double height;

public:
    /* Error!
    Since the objects of class Circle can only be constructed with a parameter,
    the cylinder's constructor needs to call base's constructor in the member
    initializer list, as in the following case.
    Cylinder(double r, double h)
    {
        Circle base(r);
        height = h;
    }
    */

    Cylinder(double r, double h) : base(r), height(h)
    {
        /* Empty body */
    }

    /* Other option:
    Cylinder(double r, double h) : base{r}, height{h}
    {
        // Empty body
    }
    */

    double volume()
    {
        return (base.area() * height);
    }
};

/************** Macros ***************/

/********************************* Constants **********************************/
const char TAB = '\t';

/********************** Functions Prototypes Declaration **********************/

/********************** Functions Templates Declaration ***********************/

/************************************ Main ************************************/
/**
 * @brief Classes are an expanded concept of data structures: like data
 * structures, they can contain data members, but they can also contain
 * functions as members.
 * An object is an instantiation of a class. In terms of variables, a class
 * would be the type, and an object would be the variable.
 *
 * @return Returns 0 when execution completes successfully.
 */
int main()
{
    /* Classes are defined with the following syntax:
    class class_name
    {
        access_specifier_1 :    // It is optionally
            member1;            // Data or Function declarations
        access_specifier_2 :
            member2;
        ...
    } object_names;

    An access specifier is one of the following three keywords:
        - private (default): Only from within other members of the same class.
        - protected: From other members of the same class and derived classes.
        - public: Accessible from anywhere where the object is visible.
    */

    /* Local Variables */ /* Objects declaration */
    Rectangle rectA;      /* Use the default constructor */
    /* Rectangle rectA();   This will be a function that takes no arguments
                                and returns a value of type Rectangle. */
    Rectangle rectB(1, 2); /* Use the overloaded constructor */
    Rectangle rectC(3, 4);
    Rectangle rectD(2, 3, 4); /* Use the second overloaded constructor */

    /* Constructors can also be called with other syntaxes: */
    Circle cirA(10.0);    /* Functional form initialization */
    Circle cirB = 20.0;   /* Variable initialization syntax */
    Circle cirC{30.0};    /* Uniform initialization */
    Circle cirD = {40.0}; /* Optionally can include an equal sign */

    Circle cirE;   /* Call the default constructor */
    Circle cirF{}; /* Also call the default constructor */
    Circle cirX(); /* Function declaration (default constructor NOT called) */

    Cylinder cylA(10.0, 20.0);

    /* Pointers to classes */
    Rectangle *p_rec_1 = nullptr;
    Rectangle *p_rec_2 = nullptr;
    Rectangle *p_rec_3 = nullptr;

    /* Processing */
    rectB.set_values(5, 6);

    p_rec_1 = &rectA;
    p_rec_2 = new (std::nothrow) Rectangle(5, 6);
    p_rec_3 = new (std::nothrow) Rectangle[2]{{3, 4}, {2, 3}};

    if ((p_rec_1 != nullptr) && (p_rec_2 != nullptr) && (p_rec_3 != nullptr))
    {

        /* Print Results */
        std::cout << "Rect A area = " << rectA.get_area() << std::endl;
        std::cout << "Rect B area = " << rectB.get_area() << std::endl;
        std::cout << "Rect C area = " << rectC.get_area() << std::endl;
        std::cout << "Rect D area = " << rectD.get_area() << std::endl;

        std::cout << "Cir A circ. = " << cirA.circumference() << std::endl;
        std::cout << "Cir B circ. = " << cirB.circumference() << std::endl;
        std::cout << "Cir C circ. = " << cirC.circumference() << std::endl;
        std::cout << "Cir D circ. = " << cirD.circumference() << std::endl;
        std::cout << "Cir E circ. = " << cirE.circumference() << std::endl;
        std::cout << "Cir F circ. = " << cirF.circumference() << std::endl;

        std::cout << "Cylinder A volume = " << cylA.volume() << std::endl;

        std::cout << "*p_rec_1's area = " << p_rec_1->get_area() << std::endl;
        std::cout << "*p_rec_2's area = " << p_rec_2->get_area() << std::endl;
        std::cout << "p_rec_3[0] area = " << p_rec_3[0].get_area() << std::endl;
        std::cout << "p_rec_3[1] area = " << p_rec_3[1].get_area() << std::endl;
    }
    else
    {
        std::cout << "Error: Memory could not be allocated" << std::endl;
    }

    /* Free used Memory */
    delete p_rec_2;
    delete[] p_rec_3;

    /* Main ended Successfully */
    return EXIT_SUCCESS;
}

/**************************** Function Definitions ****************************/
/* Classes have a special function called "constructor", which is automatically
called whenever a new object of this class is created, allowing the class to
initialize member variables or allocate storage.
It is declared like a regular member function, but with a name that matches the
class name and without any return type; not even void.                        */
Rectangle::Rectangle()
{
    width = 5;
    height = 5;
}

/* Like any other function, a constructor can also be overloaded with different
versions taking different parameters: with a different number of parameters
and/or parameters of different types.                                         */
Rectangle::Rectangle(int a, int b)
{
    width = a;
    height = b;
}

/* Member initialization: The constructor can initialize members directly
without resorting to statements in its body.
For member objects (type = class), if they are not initialized after the colon,
they are default-constructed. */
Rectangle::Rectangle(int x, int y, int z) : width(x), height(y), depth(z)
{
    /* Empty function body */
}

void Rectangle::set_values(int x, int y) /* It is a normal/not-inline function*/
{
    width = x;
    height = y;

    return;
}
