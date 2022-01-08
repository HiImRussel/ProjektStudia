#include <iostream>
#include <ctime>

#include "planned_waiting_time.h"
#include "split_and_convert_string_to_number.h"
#include "global_variables.h"

#pragma warning(disable : 4996)

using namespace std;

bool canFoodBeDeliveredAtPickedTime() {

    time_t rawtime;
    tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    int weekday = timeinfo->tm_wday;

    //current time
    int current_hour = timeinfo->tm_hour;
    int current_minutes = timeinfo->tm_min;

    //delivery hour picked by user
	int piced_delivert_hour = splitAndConvertStringToNumbers(delivery_hour)[0];
	int piced_delivery_minutes = splitAndConvertStringToNumbers(delivery_hour)[1];

    //time spend to make food
	int food_making_time = plannedWaitingTime();

    //time when food will be done
    int hour_when_food_will_be_done = current_hour;
    int minutes_when_food_will_be_done = current_minutes;

    //restaurant working hours
    int working_hour_to = 0;
    int working_minutes_to = 0;

    if (weekday >= 1 && weekday <= 5) {
        working_hour_to = splitAndConvertStringToNumbers(working_days_to)[0];
        working_minutes_to = splitAndConvertStringToNumbers(working_days_to)[1];
    }
    else if(weekday == 6) {
        working_hour_to = splitAndConvertStringToNumbers(weekend_days_to)[0];
        working_minutes_to = splitAndConvertStringToNumbers(weekend_days_to)[1];
    }

    bool minutes_added = false;

    //adding making time to current time
    float food_making_time_modulo = food_making_time / 60;

    if (food_making_time_modulo >= 1) {
        hour_when_food_will_be_done += static_cast<int>(food_making_time_modulo);

        food_making_time -= static_cast<int>(food_making_time_modulo) * 60;

        minutes_when_food_will_be_done += food_making_time;

        minutes_added = true;
    };

    if ((current_minutes + food_making_time)>=60 && !minutes_added) {
        hour_when_food_will_be_done++;
        minutes_when_food_will_be_done = ((current_minutes + food_making_time) - 60);

        minutes_added = true;
    }

    if (!minutes_added) {
        minutes_when_food_will_be_done += food_making_time;
    }

    //checking if restaurant have time to make food before delivery
    if (hour_when_food_will_be_done > piced_delivert_hour) { return false; }

    if (hour_when_food_will_be_done == piced_delivert_hour && minutes_when_food_will_be_done >= piced_delivery_minutes) { return false; }

    //check if restaurant will be close when food will be done
    if (hour_when_food_will_be_done > working_hour_to) { return false; }

    if (hour_when_food_will_be_done == working_hour_to && minutes_when_food_will_be_done >= working_minutes_to) { return false; }

	return true;
}