/* Program Name: Encoder.cpp
 * Purpose: this class encrypt a file according to a given bookfile
 * Coder: Ramon Gnan Garcia - 0926596
 * Date: Mar 28, 2020
 */

#include "Encoder.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

namespace Encoder
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
 * Purpose: it returns a string of char for the of passed as argument
 * Accepts: std::istream&
 * Returns: std::string
 * Date: Mar 22, 2020
 */
std::string retrieveTextToChar(std::istream& in)
{
    return std::string((std::istreambuf_iterator<char>(in)),
                 std::istreambuf_iterator<char>());
}


/*
 * Method Name: encodeMessage()
 * Purpose: this method encodes a message according to the bookfile
 * Accepts: std::ofstream&, std::vector<std::string>&, std::string&, std::string&
 * Returns: int
 * Date: Mar 22, 2020
 */
int encodeMessage(std::ofstream& out, std::vector<std::string>& bookCode,
        std::string& book, const std::string& message)
{
    for (const auto& c : message)
    {
        auto iterator = std::find(book.begin(), book.end(), c);

        if (iterator != book.end())
        {
            const size_t i = std::distance(book.begin(), iterator);

            out << bookCode[i] << " ";
            book.erase(book.begin() + i);
            bookCode.erase(bookCode.begin() + i);
        }
        // if a char has not been found
        // returns an error
        else
        {
            std::cerr << "ERROR: Missing character " << c << std::endl;
            return 1;
        }
    }

    return 0;
}
}
