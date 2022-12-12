/****************************** Include Headers *******************************/
#include <iostream>
#include <string>
#include <sstream>

/* Introduce the entire namespace "std" into this current declarative region
(global scope = the entire source code file).
Thus add visibility of all the entities (variables, types, constants, and
functions) of the standard C++ library and avoid the need to qualify the name.*/
// using namespace std;     <= This is considered bad practice

/********************************* Namespaces *********************************/
/**
 * Namespaces allow to group named entities into narrower scopes, giving them
 * namespace scope. This allows organizing the elements of programs into
 * different logical scopes referred to by names.
 * The syntax to declare a namespaces is:
 *      namespace identifier
 *      {
 *          named_entities      <= Set of Variables, Types and Functions
 *      }
 */
namespace myNamespaceA
{
    /* These variables can be accessed from within their namespace normally, but
    if accessed from outside the myNamespaceA namespace they have to be
    qualified with the scope operator '::'
    Syntax:
        myNamespaceA::a
    */
    int a;
    int b;
}

namespace myNamespaceB
{
    int value()
    {
        return 5;
    }
}

namespace myNamespaceC
{
    const double pi = 3.1416;

    double value()
    {
        return (2 * pi);
    }
}

/* Namespaces can be split. Two segments of a code can be declared in the same
namespace. */
namespace myNamespaceA
{
    int c;
    std::string xyz = "Hello from myNamespaceA";
}

namespace myNamespaceFirst
{
    int x = 5;
    int y = 10;
}

namespace myNamespaceSecond
{
    double x = 3.1416;
    double y = 2.7183;
}

namespace myNamespaceThird
{
    std::string xyz = "Hello";
    std::string zyx = "Bye";
}

/* Namespace aliasing: Existing namespaces can be aliased with new names.
Syntax:
    namespace new_name = current_name;
*/
namespace my_new_namespace = myNamespaceThird;

/******************************** Definitions *********************************/
#define IDENTIFIER replacement

/********************************* Constants **********************************/
const char TAB = '\t';

/********************** Functions Prototypes Declaration **********************/

/********************** Functions Templates Declaration ***********************/

/************************************ Main ************************************/
/**
 * @brief Scopes, Namespaces, using, Namespace aliasing, The std namespace and
 * Storage classes.
 *
 * @return Returns 0 when execution completes successfully.
 */
int main()
{
    /* Local Variables */

    /* Processing */
    std::cout << "myNamespaceB::value() = " << myNamespaceB::value()
              << std::endl;
    std::cout << "myNamespaceC::value() = " << myNamespaceC::value()
              << std::endl;
    std::cout << "myNamespaceC::pi      = " << myNamespaceC::pi << std::endl;

    /* The keyword "using" introduces a name into the current declarative region
    (such as this block), thus avoiding the need to qualify the name. */
    using myNamespaceFirst::x;
    using myNamespaceSecond::y;
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "myNamespaceFirst::y  = " << myNamespaceFirst::y << std::endl;
    std::cout << "myNamespaceSecond::x = " << myNamespaceSecond::x << std::endl;

    /* The keyword using can also be used as a directive to introduce an entire
    namespace: */
    using namespace myNamespaceThird;
    std::cout << "xyz = " << xyz << std::endl;

    {
        using namespace myNamespaceB;
        std::cout << "using namespace myNamespaceB => value() = " << value()
                  << std::endl;
    }
    {
        using namespace myNamespaceC;
        std::cout << "using namespace myNamespaceC => value() = " << value()
                  << std::endl;
    }

    /* Print Results */

    /* Main ended Successfully */
    return EXIT_SUCCESS;
}

/**************************** Function Definitions ****************************/
