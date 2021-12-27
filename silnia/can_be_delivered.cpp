#include <iostream>
#include <string>
#include <ctime>

#include "can_be_delivered.h"
#include "global_variables.h"
#include "split_and_convert_string_to_number.h"

#pragma warning(disable : 4996)

using namespace std;

bool checkIfCanBeDelivered(int picked_hour, int picked_minutes, int hours_from, int minutes_from, int hours_to, int minutes_to){
    if (picked_hour >= hours_from && picked_hour <= hours_to) {
        if (picked_hour == hours_to && picked_minutes > minutes_to) return false;
        return true;
    }
    else {
        return false;
    }
}

bool canBeDelivered(string delivery_hour) {
    time_t rawtime;
    tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    int weekday = timeinfo->tm_wday;

    if (delivery_hour.length() != 4 && weekday == 7) cout << "nieprawidlowa godzina";

    //checking if can be delivered in working days
    int picked_hour = splitAndConvertStringToNumbers(delivery_hour)[0];
    int picked_minutes = splitAndConvertStringToNumbers(delivery_hour)[1];

    if (weekday >= 1 && weekday <= 5) {
        int working_hour_from = splitAndConvertStringToNumbers(working_days_from)[0];
        int working_minutes_from = splitAndConvertStringToNumbers(working_days_from)[1];

        int working_hour_to = splitAndConvertStringToNumbers(working_days_to)[0];
        int working_minutes_to = splitAndConvertStringToNumbers(working_days_to)[1];

        checkIfCanBeDelivered(picked_hour, picked_minutes, working_hour_from, working_minutes_from, working_hour_to, working_minutes_to);
    }
    else if (weekday == 6) {
        //check if can be delivered in weekend working hours
        int working_hour_from = splitAndConvertStringToNumbers(weekend_days_from)[0];
        int working_minutes_from = splitAndConvertStringToNumbers(weekend_days_from)[1];

        int working_hour_to = splitAndConvertStringToNumbers(weekend_days_to)[0];
        int working_minutes_to = splitAndConvertStringToNumbers(weekend_days_to)[1];
        
        checkIfCanBeDelivered(picked_hour, picked_minutes, working_hour_from, working_minutes_from, working_hour_to, working_minutes_to);
    }
    else {
        return false;
    }
}