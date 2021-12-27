#include <iostream>
#include <string>
#include <ctime>

#include "can_be_delivered.h"
#include "split_and_convert_string_to_number.h"

#pragma warning(disable : 4996)

using namespace std;

void canBeDelivered(string delivery_hour) {
    time_t rawtime;
    tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    int weekday = timeinfo->tm_wday;

    if (delivery_hour.length() != 4 && weekday == 7) cout << "nieprawidlowa godzina";

    if (weekday >= 1 && weekday <= 5) {
        int picked_hours = splitAndConvertStringToNumbers(delivery_hour)[0];
        int picked_minutes = splitAndConvertStringToNumbers(delivery_hour)[1];

        cout << "hours: " << picked_hours << " " << "minutes: " << picked_minutes;
    }
}