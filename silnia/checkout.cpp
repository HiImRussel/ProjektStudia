#include <iostream>
#include <string>

#include "get_cart_value.h"
#include "global_variables.h"
#include "planned_waiting_time.h"
#include "can_food_be_delivered_at_picked_time.h"
#include "pick_from_menu.h"

using namespace std;
string confirm;

void checkout() {
	system("cls");

	if (!canFoodBeDeliveredAtPickedTime() && delivery_type == 2) {
		cout << "Nie mozemy zrealizowac z zamowienia w wyznaczonym czasie. Prosze zedytowac swoje zamowienie" << endl;
		cin.get();
		cin.get();

		pickFromMenu();

		exit;
	}

	cout << "----------------------------" << endl << "|  Podsumowanie zamowienia  | " << endl << "----------------------------" << endl;

	cout << "Imie: " << user_name << endl;
	cout << "Nazwisko: " << user_surname << endl << endl;

	switch (delivery_type)
	{

	case 1:
		cout << "Numer stolika: " << table_number << endl << endl;
	break;

	case 2:
		cout << "Adres: " << endl;
		cout << city << endl;
		cout << street << " " << house_number << endl << endl;

		cout << "Planowane dostarczenie na godzine: " << delivery_hour << endl << endl;
	break;
	}

	if (cart_array.size() > 0) {
		cout << "Zamowione dania: " << endl;
		for (int i = 0; i < cart_array.size  (); i++) {
			cout << i + 1 << ". " << "Danie: " << cart_array[i].name << " Ilosc porcji: " << cart_array[i].quantity << " Cena za pojedyncze danie: " << cart_array[i].price << " Cena za wszystkie porcje dania: " << cart_array[i].price * cart_array[i].quantity << endl;
		}
	}
	
	cout << endl << "Planowany czas przygotowania dan: " << plannedWaitingTime() << " min" << endl;

	cout << "[+]. Wroc do zamowienia" << endl;
	cout << "[-]. Potwierdz zamowienie" << endl;

	cout << "Prosze wybrac akcje: ";
	cin >> confirm;

	if (confirm == "+") {
		pickFromMenu();
	}

	//if (confirm == "-") {
	//	pickFromMenu(); Zapisz do pliku txt
	//}
	


}