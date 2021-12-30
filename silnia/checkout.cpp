#include <iostream>
#include <string>

#include "get_cart_value.h"
#include "global_variables.h"
#include "planned_waiting_time.h"
#include "can_food_be_delivered_at_picked_time.h"
#include "pick_from_menu.h"

using namespace std;

void checkout() {
	system("cls");

	if (!canFoodBeDeliveredAtPickedTime() && delivery_type == 2) {
		cout << "Nie mozemy zrealizowac z zamowienia w wyznaczonym czasie. Prosze zedytowac swoje zamowienie" << endl;
		
		cin.get();
		cin.get();

		pickFromMenu();

		exit;
	}

	cout << "Planowany czas przygotowania dan: " << plannedWaitingTime() << " min";
}