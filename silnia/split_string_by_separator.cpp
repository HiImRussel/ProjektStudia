#include "split_string_by_separator.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>


using namespace std;

std::vector<std::string> splitString(string string_to_split, char separator) {

    std::vector<std::string> outputArray;
    stringstream streamData(string_to_split);
    string val;
    while (std::getline(streamData, val, separator)) {
        string string_value = val;
        outputArray.push_back(val);
    }

    return outputArray;
}

