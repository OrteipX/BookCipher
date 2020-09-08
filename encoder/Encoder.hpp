/* Program Name: Encoder.hpp
 * Purpose: function headers to be implemented in Encoder.cpp
 * Coder: Ramon Gnan Garcia - 0926596
 * Date: Mar 28, 2020
 */

#ifndef ENCODER_H
#define ENCODER_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

namespace Encoder
{
    // functions headers
    void restoreFileConditionStates(std::ifstream& file);
    int encodeMessage(std::ofstream& out, std::vector<std::string>& bookCode,
            std::string& book, const std::string& message);

    std::vector<std::string> retrieveBookCode(std::istream& in);
    std::string retrieveTextToChar(std::istream& in);
};

#endif

