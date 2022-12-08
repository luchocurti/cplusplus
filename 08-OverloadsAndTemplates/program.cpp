/****************************** Include Headers *******************************/
#include <iostream>
#include <string>
#include <sstream>

/* Set the namespace (Add visibility of its components) */
using namespace std;

/******************************** Definitions *********************************/
#define IDENTIFIER replacement

/********************************* Constants **********************************/
const char TAB = '\t';

/********************** Functions Prototypes Declaration **********************/
int Operate(int a, int b);
double Operate(double a, double b);

/********************** Functions Templates Declaration ***********************/
/**
 * Define functions with generic types.
 * To overload functions that have the same body but different types.
 * Syntax:
 *      template <template-parameters> function-declaration
 *                        |
 *                        ┕->   class identifier
 *                        |         or
 *                        ┕->   typename identifier
 * Note:
 *      identifier = 'T' is common template parameter name for generic types.
 */
template <typename generic>
generic Sum(generic a, generic b);

template <class T, class U>
bool AreEqual(T a, U b);

/* The template parameters can also include constant expressions of a particular
type. In this case, the second argument of the function template is of type int.
It looks like a regular function parameter and it can be used just like one. */
template <class T, int N>
T FixedMultiply(T value);

/************************************ Main ************************************/
/**
 * @brief Different functions can have the same name if their parameters are
 * different; either because they have a different number of parameters, or
 * because any of their parameters are of a different type.
 *
 * @return Returns 0 when execution completes successfully.
 */
int main()
{
    /* Variables */
    int x = 5;
    int y = 2;
    double n = 5.0;
    double m = 2.5;
    int result_int;
    double result_double;

    /* Processing */
    result_int = Operate(x, y);
    result_double = Operate(n, m);

    /* Print results */
    cout << "Using ints    = " << result_int << endl;
    cout << "Using doubles = " << result_double << endl;

    /* Instantiating a template is applying the template to create a function
    using particular types or values for its template parameters.
    Calling the function template syntax:
        Function <template-arguments> (arguments);
    */
    result_int = Sum<int>(x, y);
    result_double = Sum<double>(n, m);

    cout << "Using ints    = " << result_int << endl;
    cout << "Using doubles = " << result_double << endl;

    /* When the compiler is able to deduce the data type automatically (no
    ambiguity), it is possible to avoid explicitly specifying the template
    arguments.
    */
    if (AreEqual(10, 10.0)) /* Equivalent to: AreEqual<int, double>(10, 10.0) */
    {
        cout << "10 and 10.0 are equal" << endl;
    }
    else
    {
        cout << "10 and 10.0 are not equal" << endl;
    }

    /* These two calls of FixedMultiply call two ≠ versions of the function */
    cout << "FixedMultiply<int,2>(10) => " << FixedMultiply<int, 2>(10) << endl;
    cout << "FixedMultiply<int,3>(10) => " << FixedMultiply<int, 3>(10) << endl;

    /* Main ended successfully */
    return EXIT_SUCCESS;
}

/**************************** Function Definitions ****************************/
int Operate(int a, int b)
{
    return (a * b);
}

double Operate(double a, double b)
{
    return (a / b);
}

template <typename generic>
generic Sum(generic a, generic b)
{
    generic result;

    result = a + b;

    return result;
}

template <class T, class U>
bool AreEqual(T a, U b)
{
    return (a == b);
}

template <class T, int N>
T FixedMultiply(T value)
{
    return (value * N);
}
