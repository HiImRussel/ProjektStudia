#include <iostream>
#include <string>
#include <ctime>

#include "can_be_delivered.h"
#include "global_variables.h"
#include "split_and_convert_string_to_number.h"

#pragma warning(disable : 4996)

using namespace std;

bool canBeDelivered(string delivery_hour) {
    time_t rawtime;
    tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    int weekday = timeinfo->tm_wday;

    if (delivery_hour.length() != 4 && weekday == 7) cout << "nieprawidlowa godzina";

    if (weekday >= 1 && weekday <= 5) {
        int picked_hour = splitAndConvertStringToNumbers(delivery_hour)[0];
        int picked_minutes = splitAndConvertStringToNumbers(delivery_hour)[1];

        int working_hour_from = splitAndConvertStringToNumbers(working_days_from)[0];
        int working_minutes_from = splitAndConvertStringToNumbers(working_days_from)[1];

        int working_hour_to = splitAndConvertStringToNumbers(working_days_to)[0];
        int working_minutes_to = splitAndConvertStringToNumbers(working_days_to)[1];

        if (picked_hour >= working_hour_from && picked_hour<=working_hour_to) {
            if (picked_hour == working_hour_to && picked_minutes > working_minutes_to) return false;
            return true;
        }
        else {
            return false;
        }
    }
    return false;
}