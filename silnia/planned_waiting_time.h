#ifndef PLANNED_WAITING_TIME
#define PLANNED_WAITING_TIME

using namespace std;

float plannedWaitingTime() {
	float total_waiting_time = 0;

	for (int i = 0; i < cart_array.size(); i++) {
		total_waiting_time += cart_array[i].quantity * 10;
	}
	return total_waiting_time;
}  
#endif
