#include <iostream>
#include <string>
#include <ctime>

#include "can_be_delivered.h"
#include "global_variables.h"
#include "split_and_convert_string_to_number.h"

#pragma warning(disable : 4996)

using namespace std;

//function check if food can be delivered in picked hour on current day and in working hours
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
    //getting current time and date
    time_t rawtime;
    tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    int weekday = timeinfo->tm_wday;

    int current_hour = timeinfo->tm_hour;
    int current_minutes = timeinfo->tm_min;

    //picked delivery hour must be a 5 character long string and current day must be other than Sunday
    if (delivery_hour.length() != 5 || weekday == 7) return false;

    //checking if can be delivered in working days
    int picked_hour = splitAndConvertStringToNumbers(delivery_hour)[0];
    int picked_minutes = splitAndConvertStringToNumbers(delivery_hour)[1];

    if (picked_hour > 24 || picked_minutes > 59) return false;

    if (picked_hour < current_hour) {
        return false;
    }
    else if(picked_hour==current_hour && picked_minutes <= current_minutes) {
        return false;
    }

    if (weekday >= 1 && weekday <= 5) {
        int working_hour_from = splitAndConvertStringToNumbers(working_days_from)[0];
        int working_minutes_from = splitAndConvertStringToNumbers(working_days_from)[1];

        int working_hour_to = splitAndConvertStringToNumbers(working_days_to)[0];
        int working_minutes_to = splitAndConvertStringToNumbers(working_days_to)[1];

        return checkIfCanBeDelivered(picked_hour, picked_minutes, working_hour_from, working_minutes_from, working_hour_to, working_minutes_to);
    }
    else if (weekday == 6 || weekday == 7 || weekday == 0) {
        //check if can be delivered in weekend working hours
        int working_hour_from = splitAndConvertStringToNumbers(weekend_days_from)[0];
        int working_minutes_from = splitAndConvertStringToNumbers(weekend_days_from)[1];

        int working_hour_to = splitAndConvertStringToNumbers(weekend_days_to)[0];
        int working_minutes_to = splitAndConvertStringToNumbers(weekend_days_to)[1];
        
        return checkIfCanBeDelivered(picked_hour, picked_minutes, working_hour_from, working_minutes_from, working_hour_to, working_minutes_to);
    }
    else {
        return false;
    }
}