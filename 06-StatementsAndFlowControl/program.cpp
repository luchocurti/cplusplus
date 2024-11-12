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
 * @brief Trying different flow controls.
 *
 * @return Returns 0 when execution completes successfully.
 */
int main()
{
    /* Variables */
    int n = 10;

    /* Processing */
    while (n > 0)
    {
        cout << n << ", ";
        --n;
    }

    /* Print results */
    cout << "liftoff!" << endl;

    string str;
    do
    {
        cout << "Enter text ('next' to continue): ";
        getline(cin, str);
        cout << "You entered: " << str << endl;
    } while (str != "next");

    for (int index = 10; index > 0; index--)
    {
        cout << index << ", ";
    }
    cout << "liftoff!" << endl;

    /* The for-loop has another syntax known as the for-each loop, which is used
    exclusively with containers that have a range of values such as an array or
    a vector.

        for (value : container) statement;                                    */
    str = "Hello!";
    for (char letter : str) /* OR: for (auto letter : str) */
    {
        cout << "[" << letter << "] ";
    }
    cout << endl;

    /* Terminate the program */
    return 0;
}
