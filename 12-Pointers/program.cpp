/****************************** Include Headers *******************************/
#include <iostream>
#include <string>
#include <sstream>
#include <array>

/********************************* Namespaces *********************************/

/******************************** Definitions *********************************/
#define IDENTIFIER replacement

/********************************* Constants **********************************/
const char TAB = '\t';

/********************** Functions Prototypes Declaration **********************/
void IncrementAll(int *start, int *stop);
void PrintAll(const int *start, const int *stop);
void IncreaseGeneric(void *data, int psize);
int Addition(int a, int b);
int Subtraction(int a, int b);
int Operation(int x, int y, int (*funcToCall)(int, int));

/********************** Functions Templates Declaration ***********************/

/************************************ Main ************************************/
/**
 * @brief When a variable is declared, the memory needed to store its value is
 * assigned a specific location in memory (its memory address). And it may be
 * useful for a program to be able to obtain the address of a variable during
 * runtime in order to access data cells that are at a certain position relative
 * to it.
 * Operators:
 *      &   <= Address-of
 *      *   <= Dereference (value pointed to by)
 *
 * @return Returns 0 when execution completes successfully.
 */
int main()
{
    /* Local Variables */
    int int_1 = 5;
    int int_2 = 15;
    // double double_1 = 3.14;
    int *p_int_1 = nullptr; /* Null pointer is a value that any pointer can */
    int *p_int_2 = nullptr; /*  take to represent it is pointing to nowhere */
    // double *p_double = &double_1;
    int array_int[5];
    unsigned int index = 0;
    const int *p_int_const = &int_1;
    int numbers[] = {10, 20, 30};
    char char_1 = 'a';
    const char *p_char_const = "hello"; /* String literal
        Array containing null-terminated character sequences */

    /* Processing */
    p_int_1 = &int_1;
    p_int_2 = &int_2;
    *p_int_1 = 10;
    *p_int_2 = *p_int_1;
    p_int_1 = p_int_2;
    *p_int_1 = 20;

    /* Print Results */
    std::cout << "int_1 = " << int_1 << std::endl;
    std::cout << "int_2 = " << int_2 << std::endl;

    p_int_1 = array_int;
    *p_int_1 = 10;
    p_int_1++;
    *p_int_1 = 20;
    p_int_1 = &array_int[2];
    *p_int_1 = 30;
    p_int_1 = array_int + 3;
    *p_int_1 = 40;
    p_int_1 = array_int;
    *(p_int_1 + 4) = 50;

    for (index = 0; index < (sizeof(array_int) / sizeof(array_int[0])); index++)
    {
        std::cout << "array_int[" << index << "] = " << array_int[index]
                  << std::endl;
    }

    int_2 = *p_int_const; // ok: reading p_int_const
    // *p_int_const = int_2; // Error: modifying a const-qualified pointer

    unsigned int sizeOfArray = sizeof(numbers) / sizeof(numbers[0]);
    IncrementAll(numbers, numbers + sizeOfArray);
    PrintAll(numbers, numbers + sizeOfArray);

    while (*p_char_const != '\0')
    {
        std::cout << *p_char_const << " ";
        p_char_const++;
    }
    std::cout << std::endl;

    std::cout << "Before increase => int_1 = " << int_1
              << " - char_1 = " << char_1 << std::endl;
    IncreaseGeneric(&int_1, sizeof(int_1));
    IncreaseGeneric(&char_1, sizeof(char_1));
    std::cout << "After increase  => int_1 = " << int_1
              << " - char_1 = " << char_1 << std::endl;

    int (*pointer_to_function)(int, int) = Subtraction;

    std::cout << "Operation(7, 5, Addition) = "
              << Operation(7, 5, Addition) << std::endl;
    std::cout << "Operation(17, " << int_2 << ", pointer_to_function) = "
              << Operation(17, int_2, pointer_to_function) << std::endl;

    /* Main ended Successfully */
    return EXIT_SUCCESS;
}

/**************************** Function Definitions ****************************/
void IncrementAll(int *start, int *stop)
{
    int *current = start;

    while (current < stop)
    {
        *current = *current + 1; // Increment value pointed
        current++;               // Increment pointer
    }

    return;
}

void PrintAll(const int *start, const int *stop)
{
    const int *current = start;

    while (current < stop)
    {
        std::cout << *current << " ";
        current++; // Increment pointer
    }
    std::cout << std::endl;

    return;
}

void IncreaseGeneric(void *data, int psize)
{
    if (psize == sizeof(char))
    {
        char *pchar;
        pchar = (char *)data;
        *pchar = *pchar + 1;
    }
    else if (psize == sizeof(int))
    {
        int *pint;
        pint = (int *)data;
        *pint = *pint + 1;
    }
    else
    {
        std::cout << "Error: IncreaseGeneric - Bad psize" << std::endl;
    }

    return;
}

int Addition(int a, int b)
{
    return (a + b);
}

int Subtraction(int a, int b)
{
    return (a - b);
}

int Operation(int x, int y, int (*p_funcToCall)(int, int))
{
    int result;

    result = (*p_funcToCall)(x, y);
    //      or
    // result = p_funcToCall(x, y);

    return result;
}
