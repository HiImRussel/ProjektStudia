#include <iostream>

#include "planned_waiting_time.h"
#include "global_variables.h"

using namespace std;

int plannedWaitingTime() {
	int total_waiting_time = 0;

	for (int i = 0; i < cart_array.size(); i++) {
		total_waiting_time += cart_array[i].quantity * making_time_per_dish;
	}
	return total_waiting_time;
}