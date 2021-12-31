#include <iostream>

#include "print_cart_items.h"
#include "global_variables.h"

using namespace std;

void printCartItems() {
	if (cart_array.size() > 0) {
		for (int i = 0; i < cart_array.size(); i++) {
			cout << i + 1 << ". " << "Danie: " << cart_array[i].name << " Ilosc porcji: " << cart_array[i].quantity << " Cena za pojedyncze danie: " << cart_array[i].price << " zl" << " Cena za wszystkie porcje dania: " << cart_array[i].price * cart_array[i].quantity << " zl" << endl;
		}
	}
	else {
		cout << "Brak dan w koszyku" << endl;
	}
}