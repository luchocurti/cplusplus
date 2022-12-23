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

/********************** Functions Templates Declaration ***********************/

/************************************ Main ************************************/
/**
 * @brief The strings can be represented as plain arrays of elements of a
 * character type.
 *
 * @return Returns 0 when execution completes successfully.
 */
int main()
{
    /* Local Variables */
    char string1[20];
    char string2[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char string3[] = "Goodbye";

    char question1[] = "What is your name? ";
    std::string question2 = "Where do you live? ";

    char answer1[80];
    std::string answer2;

    char myNtcs[] = "some text"; /* Null-Terminated Character Sequences */
    std::string myString;        /* Library string */

    /* Processing */
    string3[4] = 'B';

    std::cout << question1;
    std::cin >> answer1;
    std::cout << question2;
    std::cin >> answer2;

    myString = myNtcs; // Convert c-string to string

    /* Print Results */
    std::cout << "string1 = " << string1 << std::endl;
    std::cout << "string2 = " << string2 << std::endl;
    std::cout << "string3 = " << string3 << std::endl;

    std::cout << "Hello, " << answer1 << " from " << answer2 << std::endl;

    std::cout << "myString = " << myString
              << "\t(Print as a library string)" << std::endl;
    std::cout << "myString = " << myString.c_str()
              << "\t(Print as a c-string using c_str)" << std::endl;
    std::cout << "myString = " << myString.data()
              << "\t(Print as a c-string using data)" << std::endl;

    /* Main ended Successfully */
    return EXIT_SUCCESS;
}

/**************************** Function Definitions ****************************/
