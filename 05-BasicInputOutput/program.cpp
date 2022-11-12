/****************************** Include Headers *******************************/
#include <iostream>
#include <string>
#include <sstream>

/* Set the namespace (Add visibility of its components) */
using namespace std;

/******************************** Definitions *********************************/
#define IDENTIFIER replacement

/********************************* Constants **********************************/
const char tab = '\t';

/************************************ Main ************************************/
/**
 * @brief Use the standard library streams objects to perform input and output
 *          operations of characters.
 *
 * @return Returns 0 when execution completes successfully.
 */
int main()
{
    /* Variables */
    float x = 0.5;
    int age = 99;
    int zipcode = 1603;
    string mystring;

    /* Print strings */
    cout << "Output sentence" << endl; // prints "Output sentence" on screen
    cout << 120 << endl;               // prints number '120' on screen
    cout << x << endl;                 // prints the value of 'x' on screen
    cout << "I'm " << age << " years old and my zipcode is " << zipcode << endl;

    /* Processing */
    cout << "Please say something: ";
    getline(cin, mystring);
    // cout << "Please enter an integer value: ";
    // cin >> age; /* Always use getline() to get input in the console instead of
    //                 extracting from cin */

    /* Print results */
    cout << "You said: " << mystring << endl;
    // cout << "The value you entered is " << age;
    // cout << " and its double is " << (age * 2) << endl;

    /* The standard header <sstream> defines a type called "stringstream" that
    allows a string to be treated as a stream, and thus allowing extraction or
    insertion operations from / to strings in the same way as they are performed
    on cin and cout.
    This feature is most useful to convert strings to numerical values and vice
    versa. */
    string mystr("garbage");
    float price = 0;
    int quantity = 0;

    cout << "Enter price: ";
    getline(cin, mystr);
    stringstream(mystr) >> price; /* convert string to numerical value */

    cout << "Enter quantity: ";
    getline(cin, mystr);
    stringstream(mystr) >> quantity; /* convert string to numerical value */

    cout << "Total price: " << (price * quantity) << endl;

    /* Terminate the program */
    return 0;
}
