/****************************** Include Headers *******************************/
#include <iostream>
#include <string>

/* Set the namespace (Add visibility of its components) */
using namespace std;

/******************************** Definitions *********************************/
#define IDENTIFIER replacement

/********************************* Constants **********************************/
const char tab = '\t';

/************************************ Main ************************************/
/**
 * @brief Operate with variables and constants by using operators.
 *
 * @return Returns 0 when execution completes successfully.
 */
int main()
{
    /* Variables */
    int x;
    int y;
    int i;
    int n;
    int a;
    int b;

    /* Processing */
    x = 3;
    y = x++; /* y = 3 !!! */

    /* Print results */
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    i = 20;
    /* As the left-hand side expression is false
        The right-hand side expression is never evaluated! */
    if ((i < 10) && (++i < n))
    {
        cout << "test point 1" << endl;
    }
    else
    {
        cout << "test point 2" << endl;
    }
    cout << "i = " << i << endl;

    i = 5;
    /* As the left-hand side expression is true
        The right-hand side expression is never evaluated! */
    if ((i < 10) || (++i < n))
    {
        cout << "test point 3" << endl;
    }
    else
    {
        cout << "test point 4" << endl;
    }
    cout << "i = " << i << endl;

    /* The Comma operator ( , ) */
    a = (b = 3, b + 2);
    /* The ',' separates two or more expressions that are included
        where only one expression is expected.
        When the set of expressions has to be evaluated for a value,
        only the right-most expression is considered. */

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    /* Terminate the program */
    return 0;
}
