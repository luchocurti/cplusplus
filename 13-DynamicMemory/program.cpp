/****************************** Include Headers *******************************/
#include <iostream>
#include <string>
#include <sstream>
#include <array>
#include <new>

/********************************* Namespaces *********************************/

/******************************** Definitions *********************************/
#define IDENTIFIER replacement

/********************************* Constants **********************************/
const char TAB = '\t';

/********************** Functions Prototypes Declaration **********************/

/********************** Functions Templates Declaration ***********************/

/************************************ Main ************************************/
/**
 * @brief When the memory needs of a program can only be determined during
 * runtime (for example, when the memory needed depends on user input), programs
 * need to dynamically allocate memory. For this the C++ language integrates the
 * operators 'new' and 'delete'.
 * The C functions malloc, calloc, realloc and free are also available in C++.
 *
 * @return Returns 0 when execution completes successfully.
 */
int main()
{
    /* Local Variables */
    int *p_int = nullptr;
    int *p_int_array_1 = nullptr;
    int *p_int_array_2 = nullptr;

    unsigned int size = 0;
    unsigned int index = 0;
    int *p_int_array_3 = nullptr;

    /* Processing */
    p_int = new int;

    /* If memory allocation fails: Throw 'bad_alloc' exception */
    p_int_array_1 = new int[5];

    /* If memory allocation fails: Return is a null pointer and the program
    continues its execution. */
    p_int_array_2 = new (std::nothrow) int[5];
    if (p_int_array_2 == nullptr)
    {
        std::cout << "Error assigning memory" << std::endl;
        /* Take measures!!! */
    }

    while ((size <= 0) || (size > 10))
    {
        std::cout << "How many numbers would you like to type (1 - 10)? ";
        std::cin >> size;
    }

    p_int_array_3 = new (std::nothrow) int[size];
    if (p_int_array_3 != nullptr)
    {
        for (index = 0; index < size; index++)
        {
            std::cout << "Enter number: ";
            std::cin >> p_int_array_3[index];
        }

        /* Print Results */
        std::cout << "You have entered: ";
        for (index = 0; index < size; index++)
        {
            std::cout << p_int_array_3[index];
            if (index < (size - 1))
            {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;

        delete[] p_int_array_3;
    }
    else
    {
        std::cout << "Error: Memory could not be allocated" << std::endl;
    }

    /* Free used Memory */
    delete p_int;
    delete[] p_int_array_1;
    delete[] p_int_array_2;

    /* Main ended Successfully */
    return EXIT_SUCCESS;
}

/**************************** Function Definitions ****************************/
