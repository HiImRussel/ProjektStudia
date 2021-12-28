#include "split_and_convert_string_to_number.h"
#include "split_string_by_separator.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int* splitAndConvertStringToNumbers(string string_to_convert) {

    vector<string> outputArray = splitString(string_to_convert, ':');

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

