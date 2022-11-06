/****************************** Include Headers *******************************/
#include <iostream>
#include <string>

/* Set the namespace (Add visibility of its components) */
using namespace std;

/**
 * @brief Operating with variables.
 *
 * @return Returns 0 when execution completes successfully.
 */
int main()
{
    // Declaring variables
    int a = 5;  /* c-like initialization */
    int b (3);  /* constructor initialization */
    int c {2};  /* uniform initialization */
    int result; /* undetermined initial value */

    // Process
    a = a + b;
    result = a - c;

    // Print out the result
    cout << "Result = " << result << endl;

    // Playing with strings
    string mystring;
    mystring = "This is the initial string content";
    cout << mystring << endl;
    mystring = "This is a different string content";
    cout << mystring << endl;

    // Terminate the program
    return 0;
}
