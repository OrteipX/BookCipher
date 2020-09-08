/* Program Name: Main.cpp
 * Purpose: Main program to encrypt file
 * Coder: Ramon Gnan Garcia - 0926596
 * Date: Mar 28, 2020
 */

#include "Encoder.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

int main(int argc, char * argv[])
{
    // check the amount of args passed as arguments
    if (argc != 4)
    {
        std::cerr << "Invalid number of arguments [" << argc << "]\n";
        return 1;
    }

    std::ifstream bookFile(argv[1], std::ios::in);

    // check bookfile
    if (!bookFile)
    {
        std::cerr << "Input file opening failed\n";
        return 1;
    }

    std::ifstream messageFile(argv[2], std::ios::in);

    std::ofstream codedFile(argv[3], std::ios::out);

    // call functions
    std::vector<std::string> bookCodeVec = Encoder::retrieveBookCode(bookFile);
    std::string bookCharVec = Encoder::retrieveTextToChar(bookFile);
    const std::string messageCharVec = Encoder::retrieveTextToChar(messageFile);

    // encode message
    if (Encoder::encodeMessage(codedFile, bookCodeVec, bookCharVec, messageCharVec) == 0)
        return 0;

    return 1;

}
