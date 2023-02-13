/****************************** Include Headers *******************************/
#include <iostream>
#include <string>
#include <sstream>
#include <array>
#include <new>

/********************************* Namespaces *********************************/

/******************************** Definitions *********************************/
/************** Defines **************/
#define IDENTIFIER replacement

/************ Data Types *************/
class CVector
{
    /* private: */
    int x;
    int y;

public:
    /* Constructors */
    CVector()
    {
        x = 0;
        y = 0;
    };
    CVector(int a, int b) : x(a), y(b) {}

    /* Overloaded operators */
    /*  Member function */
    CVector operator+(const CVector &param);
    CVector &operator=(const CVector &param);
    /*  Non-member function */
    friend CVector operator-(const CVector &param_1, const CVector &param_2);

    /* Get functions */
    int get_x()
    {
        return x;
    }
    int get_y()
    {
        return y;
    }

    /* Set functions */
    void set_x(int value)
    {
        x = value;
    }
    void set_y(int value)
    {
        y = value;
    }
};

class Dummy
{
    /* private: */

public:
    /* A static data member of a class is also known as a "class variable",
    because there is only one common variable for all the objects of that same
    class, sharing the same value.
    To avoid the variable to be declared several times, it cannot be initialized
    directly in the class! */
    static int children;

    /* Constructors */
    Dummy()
    {
        children++;
    };

    /* Destructor */
    ~Dummy()
    {
        if (children > 0)
        {
            children--;
        }
    }

    /* Overloaded operators */

    /* Functions */
    bool IsItMe(Dummy &param);
};
/* Static data members of a class have the same properties as non-member
variables but with class scope (require to be accessed like a member of a class
or an object).
They need to be initialized somewhere outside the class. */
int Dummy::children = 0;

class MyClass
{
    /* private: */

public:
    int counter;

    /* Constructor */
    MyClass(int value) : counter(value)
    {
        /* Empty body */
    }

    /* It cannot be called from the object because it is not a "const" member */
    int get_A()
    {
        return counter;
    }

    /* "const" member function
            The "const" keyword follows the function prototype
            Cannot modify the state of an object */
    int get_B() const
    {
        return counter;
    }

    /* Non-const member function returning a "const &" */
    const int &get_C()
    {
        return counter;
    }

    /* Const member function returning a "const &" */
    const int &get_D() const
    {
        return counter;
    }
};

/* Like function templates, we can also create class templates, allowing classes
to have members that use template parameters as types.

The syntax is:
    template <class T>
    class class_name
    {
        ...
    };

For example, this class serves to store two elements of any valid type. */
template <class T>
class mypair
{
    /* private: */
    T values[2];

public:
    /* Constructor */
    mypair(T first, T second)
    {
        values[0] = first;
        values[1] = second;
    }

    T getmax();
};

/* Store one element of any type */
template <class T>
class mycontainer
{
    /* private: */
    T element;

public:
    /* Constructor */
    mycontainer(T arg)
    {
        element = arg;
    }

    /* Increase its value */
    T increase()
    {
        element++;

        return element;
    }
};

/* Class Template Specialization: Define a different implementation for a
template when a specific type is passed as template argument.

The syntax is:
    template <>                         // <= Empty parameter list
    class class_name <specific_type>    // <= The specialization parameter
    {
        ...
    };                                  */
template <>
class mycontainer<char>
{
    /* private: */
    char element;

public:
    /* Constructor */
    mycontainer(char arg)
    {
        element = arg;
    }

    /* Class template specialization for "char" */
    char uppercase()
    {
        if ((element >= 'a') && (element <= 'z'))
        {
            element += ('A' - 'a');
        }

        return element;
    }
};

/************** Macros ***************/

/********************************* Constants **********************************/
const char TAB = '\t';

/********************** Functions Prototypes Declaration **********************/
void my_class_print(const MyClass &arg);

/********************** Functions Templates Declaration ***********************/

/************************************ Main ************************************/
/**
 * @brief Overloading operators, the keyword "this", Static members, Const
 * member functions, Class templates and Template specialization.
 *
 * @return Returns 0 when execution completes successfully.
 */
int main()
{
    /* Local Variables */
    CVector vect_1(1, 2);
    CVector vect_2(3, 4);
    CVector vect_3;

    CVector vect_res_1;
    CVector vect_res_2;
    CVector vect_res_3;
    CVector vect_res_4;
    CVector vect_res_5;

    Dummy dummy_a;
    Dummy dummy_b;
    Dummy dummy_vect[5];
    Dummy *dummy_ptr = nullptr;

    /* When an object of a class is qualified as a "const" object:
        The access to its data members from outside the class is restricted to
            read-only
        It is limited to access only member functions marked as "const" */
    const MyClass my_class_const(10);

    /* Non-const objects can access both const and non-const member functions */
    MyClass my_class_no_const(15);

    mypair<int> my_pair_ints(115, 36);
    mypair<double> my_pair_floats(3.9, 4.18);

    mycontainer<int> my_container_int(7);     /* Normal class template */
    mycontainer<char> my_container_char('j'); /* char template specialization */

    /* Processing */
    vect_1.set_x(5);

    vect_res_1 = vect_1 + vect_2;          /* Implicitly using the operator + */
    vect_res_2 = vect_1.operator+(vect_2); /* Explicitly using functional name*/
    vect_res_3 = vect_2 - vect_1;
    vect_res_4 = vect_3.operator=(vect_1);
    vect_res_5 = vect_3 = vect_2;

    dummy_ptr = &dummy_a;

    dummy_vect[1] = dummy_b;

    // my_class_const.counter = 20; /* Not valid: The object is "const" */
    my_class_no_const.counter = 25; /* Valid: The object is not "const" */

    /* Print Results */
    std::cout << "vect_1 = ("
              << vect_1.get_x() << ", "
              << vect_1.get_y() << ")" << std::endl;
    std::cout << "vect_2 = ("
              << vect_2.get_x() << ", "
              << vect_2.get_y() << ")" << std::endl;
    std::cout << "vect_3 = ("
              << vect_3.get_x() << ", "
              << vect_3.get_y() << ")" << std::endl;

    std::cout << "vect_res_1 = ("
              << vect_res_1.get_x() << ", "
              << vect_res_1.get_y() << ")" << std::endl;
    std::cout << "vect_res_2 = ("
              << vect_res_2.get_x() << ", "
              << vect_res_2.get_y() << ")" << std::endl;
    std::cout << "vect_res_3 = ("
              << vect_res_3.get_x() << ", "
              << vect_res_3.get_y() << ")" << std::endl;
    std::cout << "vect_res_4 = ("
              << vect_res_4.get_x() << ", "
              << vect_res_4.get_y() << ")" << std::endl;
    std::cout << "vect_res_5 = ("
              << vect_res_5.get_x() << ", "
              << vect_res_5.get_y() << ")" << std::endl;

    std::cout << "dummy_ptr is ";
    if (dummy_ptr->IsItMe(dummy_a) == false)
    {
        std::cout << "NOT ";
    }
    std::cout << "equal to &dummy_a" << std::endl;

    std::cout << "dummy_ptr is ";
    if (dummy_ptr->IsItMe(dummy_b) == false)
    {
        std::cout << "NOT ";
    }
    std::cout << "equal to &dummy_b" << std::endl;

    std::cout << "Dummy has " << dummy_a.children
              << " children" << std::endl;

    dummy_ptr = new Dummy;

    std::cout << "Dummy has " << dummy_vect[3].children
              << " children now" << std::endl;

    std::cout << "my_class_const.counter    = " << my_class_const.counter
              << std::endl; /* OK: data member "counter" can be read */

    /* std::cout << "my_class_const.counter = " << my_class_const.get_A()
              << std::endl; Cannot be called because it's not a const member */

    std::cout << "my_class_no_const.counter = " << my_class_no_const.get_A()
              << std::endl; /* Can be called because it's a non-const member */

    std::cout << "my_class_const.counter    = " << my_class_const.get_B()
              << std::endl; /* Can be called because it's a const member */

    std::cout << "my_class_print(my_class_const)    = ";
    my_class_print(my_class_const);

    std::cout << "my_class_print(my_class_no_const) = ";
    my_class_print(my_class_no_const);

    std::cout << "my_pair_ints.getmax()   = "
              << my_pair_ints.getmax() << std::endl;

    std::cout << "my_pair_floats.getmax() = "
              << my_pair_floats.getmax() << std::endl;

    std::cout << "my_container_int.increase()   = "
              << my_container_int.increase() << std::endl;
    std::cout << "my_container_char.uppercase() = "
              << my_container_char.uppercase() << std::endl;

    /* Free used Memory */
    delete dummy_ptr;

    std::cout << "After delete dummy_ptr, Dummy has " << Dummy::children
              << " children" << std::endl;

    /* Main ended Successfully */
    return EXIT_SUCCESS;
}

/**************************** Function Definitions ****************************/
/* Operators are overloaded by means of operator functions, which are regular
functions with special names: their name begins by the "operator" keyword
followed by the operator sign that is overloaded.

The syntax is:
    type operator sign(parameters)
    {
        // ... body ...
    }                                */
/* Member function operator overload */
CVector CVector::operator+(const CVector &param)
{
    CVector result;

    result.x = x + param.x;
    result.y = y + param.y;

    return result;
}

CVector &CVector::operator=(const CVector &param)
{
    x = param.x;
    y = param.y;

    /* Return the object itself by reference */
    return *this;
}

/* Non-member function operator overload */
CVector operator-(const CVector &param_1, const CVector &param_2)
{
    CVector result;

    result.x = param_1.x - param_2.x;
    result.y = param_1.y - param_2.y;

    return result;
}

/* The keyword "this" represents a pointer to the object whose member function
is being executed. It is used within a class's function to refer to the object
itself. */
bool Dummy::IsItMe(Dummy &param)
{
    bool ret = false;

    /* Check if the parameter received is the object itself */
    if (&param == this)
    {
        ret = true;
    }
    else
    {
        ret = false;
    }

    return ret;
}

void my_class_print(const MyClass &arg)
{
    /* Error: const objects only have access to const member functions */
    // std::cout << arg.get_C() << std::endl;

    /* OK */
    std::cout << arg.get_D() << std::endl;

    return;
}

/* When the member function of a class template is defined outside the defintion
of the class, it must be preceded with the template <...> prefix */
template <class T>
T mypair<T>::getmax()
{
    T retval;

    retval = values[0] > values[1] ? values[0] : values[1];

    return retval;
}
