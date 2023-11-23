/****************************** Include Headers *******************************/
#include <iostream>
#include <string>
#include <sstream>
#include <array>
#include <new>

/***************************** Include Libraries ******************************/
#include "library.hpp"

/********************************* Namespaces *********************************/

/******************************** Definitions *********************************/

/************** Defines **************/

/************ Data Types *************/

/************** Macros ***************/

/********************************* Constants **********************************/

/********************** Functions Prototypes Declaration **********************/

/********************** Functions Templates Declaration ***********************/

/************************************ Main ************************************/
/**
 * @brief Friend functions and classes, inheritance between classes and multiple
 * inheritance.
 *
 * @return Returns 0 when execution completes successfully.
 */
int main()
{
    /* Local Variables */
    Rectangle rectangle_1(1, 2);
    Rectangle rectangle_2(3, 4);
    Rectangle rectangle_3(5, 6);

    Square square_1(4);

    Triangle triangle_1(7, 8);

    Mother mother_1;
    Mother mother_2(5);

    Son son_1;
    Son son_2(6);

    Daughter daughter_1;
    Daughter daughter_2(7);

    /* Processing */
    rectangle_1.set_values(2, 3);
    rectangle_2 = duplicate_rectangles(rectangle_1);
    rectangle_3.convert(square_1);

    triangle_1.set_values(5, 6);

    /* Print Results */
    std::cout << "rectangle_1.area() = " << rectangle_1.area() << std::endl;
    std::cout << "rectangle_2.area() = " << rectangle_2.area() << std::endl;
    std::cout << "rectangle_3.area() = " << rectangle_3.area() << std::endl;

    std::cout << "square_1.area()    = " << square_1.area() << std::endl;

    std::cout << "triangle_1.area()  = " << triangle_1.area() << std::endl;

    rectangle_1.print(rectangle_1.area());
    Rectangle::print(triangle_1.area());

    /* Free used Memory */

    /* Main ended Successfully */
    return EXIT_SUCCESS;
}

/**************************** Function Definitions ****************************/
