#include "split_and_convert_string_to_number.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int* splitAndConvertStringToNumbers(string string_to_convert) {

    const char separator = ':';
    vector<string> outputArray;
    stringstream streamData(string_to_convert);
    string val;
    while (std::getline(streamData, val, separator)) {
        string string_value = val;
        outputArray.push_back(val);
    }

    int array_to_return[2] = {};

    //converting string array to intiger values
    for (int i = 0;i < 2;i++) {
        string string_value = outputArray[i];
        stringstream ss(string_value);
        int strAsInt;
        ss >> strAsInt;

        array_to_return[i] = strAsInt;
    }

    return array_to_return;
}

