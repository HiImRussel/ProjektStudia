#include <iostream>
#include <fstream>

#include "write_file.h"
#include "global_variables.h"
#include "print_cart_items.h"
#include "planned_waiting_time.h"
#include "get_cart_value.h"

void writeFile()
{
	ofstream myfile;
	myfile.open("rachunek.txt");
	myfile << "Imie: " << user_name << endl;
	myfile << "Nazwisko: " << user_surname << endl << endl;

	switch (delivery_type)
	{

	case 1:
		myfile << "Numer stolika: " << table_number << endl << endl;
		break;

	case 2:
		myfile << "Adres: " << endl;
		myfile << city << endl;
		myfile << street << " " << house_number << endl << endl;

		myfile << "Planowane dostarczenie na godzine: " << delivery_hour << endl << endl;
		break;
	}

	myfile << "Zamówione dania: " << endl;
	for (int i = 0; i < cart_array.size(); i++) {
		myfile << i + 1 << ". " << "Danie: " << cart_array[i].name << " Ilosc porcji: " << cart_array[i].quantity << " Cena za pojedyncze danie: " << cart_array[i].price << " zl" << " Cena za wszystkie porcje dania: " << cart_array[i].price * cart_array[i].quantity << " zl" << endl;
	}

	myfile << endl << "Planowany czas przygotowania dan: " << plannedWaitingTime() << " min" << endl << endl;
	myfile << "Do zaplaty: " << getCartValue() << " zl" << endl << endl;
	myfile.close();

	system("cls");
	cout << "Zamowienie zatwierdzone, smacznego!" << endl;
}
