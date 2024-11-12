/************************************ Main ************************************/
/**
 * @file    main.cpp
 * @brief   Input Parameters and streams
 * @return  xxx
 */

#include <iostream>
#include <string>
#include <sstream>
#include <array>
#include <new>
#include <random>
#include <iomanip>
#include <filesystem>

/*
The program will take as input only 2 arguments.
Both arguments will be filenames with the following format: "<INT>.<EXT>"
*/
auto main(int argc, char *argv[]) -> int
{
    /* variables */
    bool debug = true;

    if (debug)
    {
        std::cout << "Number of arguments = " << argc << std::endl;

        for (int i = 0; i < argc; ++i)
        {
            std::cout << "   " << i << " - " << argv[i] << std::endl;
        }
    }

    /* Check that only two and just two input arguments are provided to the
    program, otherwise print an error msg and abort the execution */
    if (argc == 3)
    {
        /* OK. Continue */

        /* variables */
        // std::string name_1;
        // std::string ext_1;
        // std::string name_2;
        // std::string ext_2;

        // Combine variables into a stringstream.
        // std::stringstream filename_1{argv[1]};
        // std::stringstream filename_2{argv[2]};
        std::string s1 = argv[1];
        std::string e1 = "";

        size_t i = s1.rfind('.', s1.length());
        if (i != std::string::npos)
        {
            e1 = s1.substr(i + 1, s1.length() - i);
        }

        // Split the string stream using simple syntax
        // filename_1 >> name_1 >> ext_1;
        // filename_2 >> name_2 >> ext_2;

        // if (debug)
        // {
        //     std::cout << "name_1 = " << name_1 << std::endl;
        //     std::cout << "ext_1  = " << ext_1 << std::endl;
        //     std::cout << "name_2 = " << name_2 << std::endl;
        //     std::cout << "ext_2  = " << ext_2 << std::endl;
        // }

        /* If the files are with ".txt" extension, you need to output the mean
        value between the first and last number provided in the arguments */

        return EXIT_SUCCESS;
    }
    else
    {
        std::cout << "ERROR. Number of arguments != 2" << std::endl;

        return EXIT_FAILURE;
    }
}
