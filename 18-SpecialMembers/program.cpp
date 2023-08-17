/****************************** Include Headers *******************************/
#include "program.hpp"

/********************************* Namespaces *********************************/

/******************************** Definitions *********************************/
/************** Defines **************/
#define IDENTIFIER replacement

/************ Data Types *************/
class ConstructorExample
{
    /* private: */

public:
    /* Data members */
    int total;

    /* Constructors */
    /* "Default constructor" ClassName::ClassName();
        It is the implicitly default constructor created when objects of a class
        are declared without any arguments and the class definition has no
        constructors. */

    /* Destructor */

    /* Overloaded operators */

    /* Functions */
    void set_total(int x)
    {
        total = x;
    }

    void accumulate(int x)
    {
        total += x;
    }
};

class DestructorExample
{
    /* private: */
    std::string *string_p;
    std::string string_e = "<empty>";

public:
    /* Data members */

    /* Constructors */
    DestructorExample() : string_p(new std::string) {}
    DestructorExample(const std::string &string_a) : string_p(new std::string(string_a)) {}

    /* "Destructor" ClassName::~ClassName();
        It is a function called automatically at the end of the object's
        lifetime, that takes no arguments and returns nothing, not even void. */
    ~DestructorExample()
    {
        delete string_p;
    }

    /* Overloaded operators */

    /* Functions */
    const std::string &content() const
    {
        if (!string_p->empty())
        {
            return *string_p;
        }
        else
        {
            return string_e;
        }
    }
};

class CopyConstructorExample
{
    /* private: */
    std::string *string_p;
    std::string string_e = "<empty>";

public:
    /* Data members */

    /* Constructors */
    CopyConstructorExample(const std::string &string_a) : string_p(new std::string(string_a)) {}
    /* "Copy constructor" ClassName::ClassName(const ClassName &param);
        It is invoked to construct a copy when an object is passed a named
        object of its own type as argument. Used at object initialization. */
    CopyConstructorExample(const CopyConstructorExample &x) : string_p(new std::string(x.content() + "_copy")) {}

    /* Destructor */
    ~CopyConstructorExample()
    {
        delete string_p;
    }

    /* Overloaded operators */

    /* Functions */
    const std::string &content() const
    {
        if (!string_p->empty())
        {
            return *string_p;
        }
        else
        {
            return string_e;
        }
    }
};

class CopyAssignmentExample
{
    /* private: */
    std::string *string_p;
    std::string string_e = "<empty>";

public:
    /* Data members */

    /* Constructors */
    CopyAssignmentExample() : string_p(new std::string) {}
    CopyAssignmentExample(const std::string &string_a) : string_p(new std::string(string_a)) {}

    /* Destructor */
    ~CopyAssignmentExample()
    {
        delete string_p;
    }

    /* Overloaded operators */
    /* "Copy assignment operator" ClassName &operator=(const ClassName &param);
        It is an overload of operator= which takes a value or reference of the
        class itself as parameter. The return value is a reference to *this.
        The copy assignment operator is defined implicitly if a class has no
        custom copy nor move assignments defined. */
    CopyAssignmentExample &operator=(const CopyAssignmentExample &x)
    {
        *string_p = x.content() + "_copy_operator";

        return *this;
    }

    /* Functions */
    const std::string &content() const
    {
        if (!string_p->empty())
        {
            return *string_p;
        }
        else
        {
            return string_e;
        }
    }
};

class MoveConstructorAssignmentExample
{
    /* private: */
    std::string *string_p;
    std::string string_e = "<empty>";

public:
    /* Data members */

    /* Constructors */
    MoveConstructorAssignmentExample() : string_p(new std::string) {}
    MoveConstructorAssignmentExample(const std::string &string_a) : string_p(new std::string(string_a)) {}

    /* Destructor */
    ~MoveConstructorAssignmentExample()
    {
        delete string_p;
    }

    /* "Move-Constructor" ClassName(ClassName &&param);
       The Move Constructor is called when an object is initialized on
       construction using a temporary object (for example: return values).
       Example:
        ClassName objectName = function_that_return_ClassName_object(); */
    MoveConstructorAssignmentExample(MoveConstructorAssignmentExample &&x) : string_p(x.string_p)
    {
        x.string_p = nullptr;
    }

    /* Overloaded operators */
    /* "Move-Assignment" ClassName &operator=(ClassName &&param);
       The Move Assignment is called when an object is assigned the value of a
       temporary object (for example: return values).
       Example:
        objectName = ClassName(); */
    MoveConstructorAssignmentExample &operator=(MoveConstructorAssignmentExample &&x)
    {
        delete string_p;
        string_p = x.string_p;
        x.string_p = nullptr;
        return *this;
    }

    MoveConstructorAssignmentExample operator+(const MoveConstructorAssignmentExample &rhs)
    {
        return MoveConstructorAssignmentExample(content() + " + " + rhs.content());
    }

    /* Functions */
    const std::string &content() const
    {
        if (!string_p->empty())
        {
            return *string_p;
        }
        else
        {
            return string_e;
        }
    }
};

/************** Macros ***************/

/********************************* Constants **********************************/
const char TAB = '\t';

/********************** Functions Prototypes Declaration **********************/

/********************** Functions Templates Declaration ***********************/

/************************************ Main ************************************/
/**
 * @brief Special member functions are member functions that are implicitly
 * defined as member of classes under certain circumstances.
 *
 * @return Returns 0 when execution completes successfully.
 */
int main()
{
    /* Local Variables */
    ConstructorExample constructor;

    DestructorExample destructor1;
    DestructorExample destructor2("destructor2");

    CopyConstructorExample copyConstructor1("copyConstructor1");
    // Call the copy constructor
    CopyConstructorExample copyConstructor2 = copyConstructor1;
    // Call the copy constructor
    CopyConstructorExample copyConstructor3(copyConstructor2);

    CopyAssignmentExample copyAssignment1("copyAssignment1");
    CopyAssignmentExample copyAssignment2;

    MoveConstructorAssignmentExample moveConstructorAssignment1("moveConstructorAssignment1");
    // Move-Construction
    MoveConstructorAssignmentExample moveConstructorAssignment2 =
        MoveConstructorAssignmentExample("moveConstructorAssignment2");

    /* Processing */
    constructor.set_total(10);
    constructor.accumulate(5);

    copyAssignment2 = copyAssignment1; // Call the copy assignment operation

    // Move-Assignment
    moveConstructorAssignment1 = moveConstructorAssignment1 + moveConstructorAssignment2;

    /* Print Results */
    std::cout << "constructor.total = " << constructor.total << std::endl;

    std::cout << "destructor1's content = " << destructor1.content() << std::endl;
    std::cout << "destructor2's content = " << destructor2.content() << std::endl;

    std::cout << "copyConstructor1's content = " << copyConstructor1.content() << std::endl;
    std::cout << "copyConstructor2's content = " << copyConstructor2.content() << std::endl;
    std::cout << "copyConstructor3's content = " << copyConstructor3.content() << std::endl;

    std::cout << "copyAssignment1's content = " << copyAssignment1.content() << std::endl;
    std::cout << "copyAssignment2's content = " << copyAssignment2.content() << std::endl;

    std::cout << "moveConstructorAssignment1's content: " << moveConstructorAssignment1.content() << std::endl;
    std::cout << "moveConstructorAssignment2's content: " << moveConstructorAssignment2.content() << std::endl;

    /* Free used Memory */

    /* Main ended Successfully */
    return EXIT_SUCCESS;
}

/**************************** Function Definitions ****************************/
