/****************************** Include Headers *******************************/
#include <iostream>
#include <string>

/* Set the namespace (Add visibility of its components) */
using namespace std;

/******************************** Definitions *********************************/
#define PI      3.14159
#define NEWLINE '\n'

/********************************* Constants **********************************/
const double pi = 3.1415926;
const char tab = '\t';

/************************************ Main ************************************/
/**
 * @brief Constants are expressions with a fixed value.
 *
 * @return Returns 0 when execution completes successfully.
 */
int main()
{
    /* Variables */
    double radius = 5.0;
    double circle;

    /* Processing */
    circle = 2.0 * pi * radius;
    cout << "circle = " << circle << endl;

    radius = 7.5;
    circle = 2.0 * PI * radius;
    cout << "circle = " << circle << NEWLINE;

    /* Strings */
    string mystring = "string expressed in \
two lines";

    cout << "this forms " "a single"    " string "
            " of characters" << endl;
    cout << mystring << endl;
    cout << R"(string with \backslash)" << endl;

    /* Terminate the program */
    return 0;
}
