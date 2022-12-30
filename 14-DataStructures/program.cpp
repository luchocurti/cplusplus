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
struct product /* The type name is optional if objects are declared at the end*/
{
    int weight;
    double price;
}; /* The objects can also be declared here */

struct movies_t
{
    std::string title;
    int year;
};

/* Nesting Structures */
struct friends_t
{
    std::string name;
    std::string email;
    movies_t favorite_movie;
};

/************** Macros ***************/

/********************************* Constants **********************************/
const char TAB = '\t';

/********************** Functions Prototypes Declaration **********************/
std::string PrintMovie(movies_t movie);

/********************** Functions Templates Declaration ***********************/

/************************************ Main ************************************/
/**
 * @brief A data structure is a group of data elements grouped together under
 * one name. These data elements, known as members, can have different types and
 * different lengths.
 *
 * @return Returns 0 when execution completes successfully.
 */
int main()
{
    /* Local Variables */
    // product apple;
    // product banana;
    // product melon;

    movies_t mine;
    movies_t yours;

    movies_t films[3]; /* Array of structs */

    friends_t charlie;
    friends_t maria;

    /* Pointers to Structures */
    movies_t *p_movie = nullptr;
    friends_t *p_friends = nullptr;

    std::string mystr;

    /* Processing */
    mine.title = "A Space Odyssey";
    mine.year = 1968;

    p_movie = &yours;

    std::cout << "Enter movie title: ";
    getline(std::cin, p_movie->title);

    std::cout << "Enter movie year: ";
    getline(std::cin, mystr);
    std::stringstream(mystr) >> p_movie->year; /* Convert string to integer */

    films[1].title = "Blade Runner";
    films[1].year = 1982;

    p_friends = &charlie;

    charlie.name = "Carlitos";
    p_friends->email = "carlos@hotmail.com";
    p_friends->favorite_movie.title = "The Ozarks";
    charlie.favorite_movie.year = 2010;

    /* Print Results */
    std::cout << std::endl;
    std::cout << "My favorite movie is: " << PrintMovie(mine) << std::endl;
    std::cout << "And yours is: " << TAB << PrintMovie(yours) << std::endl;
    std::cout << "Film #1 is: " << TAB << PrintMovie(films[1]) << std::endl;
    std::cout << "Charlie's movie is: " << PrintMovie(charlie.favorite_movie);
    std::cout << std::endl;

    /* Free used Memory */

    /* Main ended Successfully */
    return EXIT_SUCCESS;
}

/**************************** Function Definitions ****************************/
std::string PrintMovie(movies_t movie)
{
    std::string mystr;

    mystr = TAB + movie.title + " (" + std::to_string(movie.year) + ")";

    return mystr;
}
