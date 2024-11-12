/************************************ Main ************************************/
/**
 * @file    main.cpp
 * @brief   Small "guessing" game
 * @return  xxx
 */

#include <iostream>
#include <string>
#include <sstream>
#include <array>
#include <new>
#include <random>

/*

    VER

        https://danielsieger.com/blog/2021/12/21/clang-tidy-cmake.html
        https://dev.to/batunpc/static-analysis-tooling-with-cmake-6m7

*/

auto main() -> int
{
    std::cout << "the guessing game" << std::endl;

    /* variables */
    std::string user_str;
    int random_number = 0;
    int user_number = 0;
    bool running = true;

    /* will pick a random number from 0 to 99 */
    /*  => use a random_device: https://en.cppreference.com/w/cpp/numeric/random/random_device */
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, 99);
    random_number = dist(rd);

    while (running)
    {
        /* by providing your guess through stdin */
        std::cout << std::endl
                  << "Enter a number: ";
        getline(std::cin, user_str);

        /* convert string to numerical value */
        std::stringstream user_stream(user_str);
        user_stream >> user_number;

        if (user_stream.fail())
        {
            /* if a failure is encountered (use std::cin.fail() to check for errors in the stdin)
                => return an error code(1)
                => print this exact string: "Error encountered, exiting..." */
            std::cout << "Error encountered, exiting..." << std::endl;

            return EXIT_FAILURE;
        }
        else
        {
            if ((user_number >= 0) && (user_number <= 99))
            {
                /* You have guessed the number => Then the program has to tell you that you have won */
                if (user_number == random_number)
                {
                    std::cout << "you have won" << std::endl;

                    running = false;
                }

                /* Your number if larger than the target one => The program should tell you that it’s number is smaller */
                if (user_number > random_number)
                {
                    std::cout << "the number is smaller" << std::endl;
                }

                /* Your number is smaller than the target one => The program should tell you that its number is larger */
                if (user_number < random_number)
                {
                    std::cout << "the number is larger" << std::endl;
                }

                /* if not guess => restart */
            }
            else
            {
                /* if the user provides an invalid input
                    => print a warning msg to the stderr using this exact string: "[WARNING] : Number must be between 0 and 99" */
                std::cerr << "[WARNING] : Number must be between 0 and 99" << std::endl;
            }
        }
    }

    /* output the generated random numnber */
    std::cout << "generated random numnber = " << random_number << std::endl;

    return EXIT_SUCCESS;
}
