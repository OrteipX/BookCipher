/* Program Name: Decoder.cpp
 * Purpose: this class decrypt a file according to a given bookfile
 * Coder: Ramon Gnan Garcia - 0926596
 * Date: Mar 28, 2020
 */

#include "Decoder.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

namespace Decoder
{
/*
 * Method Name: restoreFileConditionStates()
 * Purpose: this function let's you to restore the file to the beginning of it state, so
 * you can reuse it and iterate through it
 * Accepts: std::istream&
 * Returns: void
 * Date: Mar 22, 2020
 */
void restoreFileConditionStates(std::istream& file)
{
    file.clear();
    file.seekg(0, std::ios::beg);
}


/*
 * Method Name: retrieveBookCode()
 * Purpose: this function maps the bookfile into a bookfile code, which means that each
 * letter has a pageNum, lineNum and columnNum
 * Accepts: std::istream&
 * Returns: std::vector<std::string>
 * Date: Mar 22, 2020
 */
std::vector<std::string> retrieveBookCode(std::istream& in)
{
    // variables declaration
    char ch;
    size_t pageNum = 0;
    size_t lineNum = 0;
    size_t columnNum = 0;

    std::vector<std::string> bookCode;

    // while loop to create each code
    while (in.get(ch))
    {
        const std::string code = std::to_string(pageNum)
            + ',' + std::to_string(lineNum)
            + ',' + std::to_string(columnNum);

        bookCode.push_back(code);

        ++columnNum;

        if (ch == '\n')
        {
            ++lineNum;
            columnNum = 0;
        }
        if (ch == '\f')
        {
            ++pageNum;
            lineNum = 0;
            columnNum = 0;
        }
    }

    // restore file state
    restoreFileConditionStates(in);

    return bookCode;
}


/*
 * Method Name: retrieveTextToChar()
 * Purpose: it returns a string of char of the file passed as argument
 * Accepts: std::istream&
 * Returns: std::string
 * Date: Mar 22, 2020
 */
std::string retrieveCharToText(std::istream& in)
{
    return std::string((std::istreambuf_iterator<char>(in)),
                 std::istreambuf_iterator<char>());
}


/*
 * Method Name: decodeMessage()
 * Purpose: this method decodes a message according to the bookfile
 * Accepts: std::ifstream&, std::ofstream&, std::vector<std::string>, std::string
 * Returns: void
 * Date: Mar 22, 2020
 */
void decodeMessage(std::ifstream& in, std::ofstream& out, const std::vector<std::string> bookCode, const std::string bookText)
{
    std::string codedMessage;

    while (in >> codedMessage)
    {
        for (size_t i = 0; i < bookCode.size(); ++i)
        {
            if (codedMessage == bookCode[i])
            {
                out << bookText[i];
                break;
            }
        }
    }
}
}
