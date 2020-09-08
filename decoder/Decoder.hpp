/* Program Name: Decoder.hpp
 * Purpose: function headers to be implemented in Decoder.cpp
 * Coder: Ramon Gnan Garcia - 0926596
 * Date: Mar 28, 2020
 */

#ifndef DECODER_H
#define DECODER_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

namespace Decoder
{
    // function headers
    void restoreFileConditionStates(std::ifstream& file);
    void decodeMessage(std::ifstream& in, std::ofstream& out,
            const std::vector<std::string> bookCode, const std::string bookText);

    std::vector<std::string> retrieveBookCode(std::istream& in);
    std::string retrieveCharToText(std::istream& in);
};

#endif

