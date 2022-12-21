/****************************** Include Headers *******************************/
#include <iostream>
#include <string>
#include <sstream>
#include <array>

/********************************* Namespaces *********************************/

/******************************** Definitions *********************************/
#define IDENTIFIER replacement

#define HEIGHT 3
#define WIDTH 5

/********************************* Constants **********************************/
const char TAB = '\t';

/********************** Functions Prototypes Declaration **********************/
void PrintArray1D(std::string name, int arg[], unsigned int length);
void PrintArray2D(std::string name, int arg[], unsigned int length,
                  unsigned int width);

/********************** Functions Templates Declaration ***********************/

/************************************ Main ************************************/
/**
 * @brief An array is a series of elements of the same type placed in contiguous
 * memory locations that can be individually referenced by adding an index to a
 * unique identifier.
 *
 * @return Returns 0 when execution completes successfully.
 */
int main()
{
    /* Local Variables */
    unsigned int index = 0;
    // int array[5];                                /* Init with garbage   */
    // int array[5] = {16, 2, 77, 40, 12071};       /* Normal init         */
    // int array[5] = {16, 2, 77, 40, 12071, 67};   /* Error               */
    // int array[5] = {16, 2, 77};                  /* Filled with zeros   */
    // int array[5] = {};                           /* Init all with zeros */
    // int array[]  = {16, 2, 77, 40, 12071};       /* Create 5 elements   */
    int array[]{16, 2, 77, 40, 12071}; /* C++ universal init without '='   */
    int result = 0;
    int firstArray[] = {3, 5, 7};
    int secondArray[] = {2, 4, 6, 8, 10};

    /* Processing */
    for (index = 0; index < (sizeof(array) / sizeof(array[0])); index++)
    {
        std::cout << "index = " << index << " - value = " << array[index]
                  << std::endl;

        result += array[index];
    }
    std::cout << "result   = " << result << std::endl;
    array[2] = 8;
    std::cout << "array[2] = " << array[2] << std::endl;

    int bidimensional_array[HEIGHT][WIDTH];
    int multidimensional_array[24][60][60];
    unsigned int row = 0;
    unsigned int column = 0;
    for (row = 0; row < HEIGHT; row++)
    {
        for (column = 0; column < WIDTH; column++)
        {
            bidimensional_array[row][column] = row * column;
        }
    }
    result = sizeof(multidimensional_array) /
             sizeof(multidimensional_array[0][0][0]);

    /* Print Results */
    PrintArray1D("firstArray", firstArray,
                 sizeof(firstArray) / sizeof(firstArray[0]));
    PrintArray1D("secondArray", secondArray,
                 sizeof(secondArray) / sizeof(secondArray[0]));
    PrintArray2D("bidimensional_array", bidimensional_array[0],
                 sizeof(bidimensional_array) /
                     sizeof(bidimensional_array[0][0]),
                 sizeof(bidimensional_array[0]) /
                     sizeof(bidimensional_array[0][0]));

    std::cout << "multidimensional_array size = " << result << std::endl;

    /* C++ provides an alternative array type as a standard container.
    It is a type (class) template defined in header "array". */
    std::array<int, 3> arrayInt3 = {1, 2, 3};
    std::array<std::string, 2> arrayStr2 = {std::string("abc"), "xyz"};

    /* Accessing the "size" of the library array */
    for (index = 0; index < arrayInt3.size(); index++)
    {
        arrayInt3[index] = arrayInt3[index] + 1;
    }

    std::cout << "arrayInt3 = ";
    for (int element : arrayInt3)
    {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    std::cout << "arrayStr2 = ";
    for (std::string word : arrayStr2)
    {
        std::cout << word << ' ';
    }
    std::cout << std::endl;

    /* Main ended Successfully */
    return EXIT_SUCCESS;
}

/**************************** Function Definitions ****************************/
void PrintArray1D(std::string name, int arg[], unsigned int length)
{
    unsigned int index = 0;

    std::cout << name << " = ";
    for (index = 0; index < length; index++)
    {
        std::cout << arg[index] << " ";
    }
    std::cout << std::endl;

    return;
}

void PrintArray2D(std::string name, int arg[], unsigned int length,
                  unsigned int width)
{
    unsigned int row = 0;
    unsigned int column = 0;
    unsigned int height = length / width;

    std::cout << name << "[" << height << "][" << width << "] = " << std::endl;
    for (row = 0; row < height; row++)
    {
        for (column = 0; column < width; column++)
        {
            std::cout << " " << arg[row * width + column];
        }
        std::cout << std::endl;
    }

    return;
}
