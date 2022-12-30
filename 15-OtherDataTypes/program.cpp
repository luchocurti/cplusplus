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
union mytypes_t
{
    unsigned char c;
    unsigned short s;
    unsigned int i;
};

union mix_t
{
    int l;
    struct
    {
        short hi;
        short lo;
    } s;
    char c[4];
};

/* Structure with regular union */
struct book1_t
{
    char title[50];
    char author[50];
    union
    {
        float dollars; /* Access as: book1.price.dollars */
        int yen;
    } price;
};

/* Structure with anonymous union */
struct book2_t
{
    char title[50];
    char author[50];
    union
    {
        float dollars; /* Access as: book1.dollars (without "price") */
        int yen;
    }; /* When unions are members of a class (or structure),
            they can be declared with no name. */
};

/* Enumerated types are types that are defined with a set of custom identifiers,
known as enumerators, as possible values. Objects of these enumerated types can
take any of these enumerators as value. */
enum colors_t
{
    blue = 10,
    green,
    red,
};

enum months_t
{
    january = 1,
    february,
    march,
    april,
    may,
    june,
    july,
    august,
    september,
    october,
    november,
    december
};

/* Enumerated types with enum class */
enum class Colors /* or => enum struct Colors */
{
    black,
    grey,
    white,
};

enum class EyeColor : char /* Optional: Set the data type (char, int, ...) */
{
    blue,
    green,
    brown,
};

/************** Macros ***************/

/********************************* Constants **********************************/
const char TAB = '\t';

/********************** Functions Prototypes Declaration **********************/
void PrintUnionMytypes(mytypes_t *p_union);

/********************** Functions Templates Declaration ***********************/

/************************************ Main ************************************/
/**
 * @brief Type Aliases (typedef / using), Unions, Anonymous Unions, Numerated
 * types (enum), and Enumerated types with enum class.
 *
 * @return Returns 0 when execution completes successfully.
 */
int main()
{
    /* A type alias is a different name by which a type can be identified. */
    /* Syntax #1 - Inherited from the C, uses the "typedef" keyword:
            typedef existing_type new_type_name;                              */
    typedef char *pChar;
    /* Syntax #2 - Introduced in the C++, uses the "using" keyword:
            using new_type_name = existing_type;                              */
    using WORD = unsigned int;

    /* Local Variables */
    pChar ptc2 = nullptr;
    WORD myword;
    mytypes_t mytypes;
    mytypes_t *p_mytypes = nullptr;
    mix_t mix;
    colors_t color;
    months_t y2k;
    Colors mycolor;

    /* Processing */
    myword = 14;
    ptc2 = (pChar)&myword;
    *ptc2 = 15;
    p_mytypes = &mytypes;
    mix.s.lo = 0xDEAD;
    mix.c[1] = 0xBE;
    mix.c[0] = 0xEF;
    color = green;
    y2k = november;

    // std::cout << "Size of char    = " << sizeof(mytypes.c) << std::endl; // 1
    // std::cout << "Size of short   = " << sizeof(mytypes.s) << std::endl; // 2
    // std::cout << "Size of int     = " << sizeof(mytypes.i) << std::endl; // 4
    // std::cout << "Size of mytypes = " << sizeof(mytypes) << std::endl;   // 4

    /* Print Results */
    if (color == green)
    {
        color = red;
    }
    std::cout << "color = " << color << std::endl;
    std::cout << "month = " << y2k << std::endl;

    /* Enumerated types with enum class */
    mycolor = Colors::black;
    if (mycolor == Colors::white)
    {
        mycolor = Colors::grey;
    }

    mytypes.i = 0x12345678;
    PrintUnionMytypes(p_mytypes);

    mytypes.c = 0xAF;
    PrintUnionMytypes(p_mytypes);

    std::cout << std::endl
              << "mix = 0x" << mix.l << std::endl;

    /* Free used Memory */

    /* Main ended Successfully */
    return EXIT_SUCCESS;
}

/**************************** Function Definitions ****************************/
void PrintUnionMytypes(mytypes_t *p_union)
{
    std::cout << std::uppercase << std::hex << std::endl;

    /*                              Print the character as an integer */
    std::cout << "char value  =       0x" << (int)(p_union->c) << std::endl;
    std::cout << "short value =     0x" << p_union->s << std::endl;
    std::cout << "int value   = 0x" << p_union->i << std::endl;

    return;
}
