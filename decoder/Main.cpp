/* Program Name: Main.cpp
 * Purpose: Main program to decrypt file
 * Coder: Ramon Gnan Garcia - 0926596
 * Date: Mar 28, 2020
 */

#include "Decoder.hpp"

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

    std::ifstream codedFile(argv[2], std::ios::in);

    std::ofstream messageFile(argv[3], std::ios::out);

    // call functions
    const std::vector<std::string> bookCodeVec = Decoder::retrieveBookCode(bookFile);
    const std::string bookText = Decoder::retrieveCharToText(bookFile);

    // decode the message
    Decoder::decodeMessage(codedFile, messageFile, bookCodeVec, bookText);

}
