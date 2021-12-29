#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

#include "checkout.h"
#include "split_string_by_separator.h"
#include "order_class.h"
#include "global_variables.h"
#include "order_class.h"
#include "search_for_item_in_menu.h"
#include "get_cart_value.h"

using namespace std;

vector<Order> cart_array;

void addProductToCart(string id, int quantity) {
	Order* newOrder = searchForItemInMenu(id, quantity);

	bool isItemInCart = false;

	for (int i = 0; i < cart_array.size(); i++) {
		if (cart_array[i].id == id) {
			cart_array[i].quantity += quantity;
			isItemInCart = true;
		}
	}

	if (newOrder != NULL && !isItemInCart) {
		cart_array.push_back(Order(newOrder->id, newOrder->name, newOrder->price, newOrder->quantity));
	}

	if(newOrder == NULL) {
		system("cls");

		cout << "W menu nie znaleziono produktu o podanym identyfikatorze" << endl;
		cin.get();
		cin.get();
	}
}

void removeFromCart(string index) {
	int prevCartSize = cart_array.size();
	
	stringstream ss(index);
	int strAsInt;
	ss >> strAsInt;

	if (strAsInt > 0) {
		cart_array.erase(cart_array.begin() + (strAsInt - 1));
	}

	if (prevCartSize == cart_array.size()) {
		system("cls");

		cout << "Produktu o podanym identyfikatorze nie ma w koszyku" << endl;
		cin.get();
		cin.get();
	}
}

void editCart() {
	string index_of_an_item;

	do {
		system("cls");

		if (cart_array.size() > 0) {
			cout << "Koszyk: " << endl;
			for (int i = 0; i < cart_array.size(); i++) {
				cout << i+1 << ". " << "Danie: " << cart_array[i].name << " Ilosc porcji: " << cart_array[i].quantity << " Cena za pojedyncze danie: "<< cart_array[i].price << " Cena za wszystkie porcje dania: " << cart_array[i].price * cart_array[i].quantity << endl;
			}
		}
		else {
			cout << "Brak dan w koszyku" << endl;
		}

		cout << "[-]. Wroc" << endl;

		cout << "Wybierz element do usuniecia lub akcje: ";
		cin >> index_of_an_item;

		if (index_of_an_item != "-") {
			removeFromCart(index_of_an_item);
		}
	} while (index_of_an_item != "-");
}

void setQuantity(string id) {
	int quantity;

	do {
		system("cls");

		cout <<"Podaj ilosc porcji: ";
		cin >> quantity;

		if(quantity > 0) {
			addProductToCart(id, quantity);
		}
		else {
			system("cls");
			cout << "Ilosc musi byc wieksza od 0" << endl;
		}
	} while (quantity <= 0);
}

void pickFromMenu() {
	string id;

	do {
		system("cls");

		cout << "Menu: " << endl;

		vector<vector<string>> Menu;
		vector<string> row;
		string line, word;

		fstream file("menu.csv");
		if (file.is_open())
		{
			while (getline(file, line))
			{
				row.clear();

				std::stringstream str(line);

				while (getline(str, word, ';'))
					row.push_back(word);
				Menu.push_back(row);
			}
		}
		for (int i = 0; i < Menu.size(); i++)
		{
			for (int j = 0; j < Menu[i].size(); j++)
			{
				if (j == 2) {
					cout << "Cena: ";
				}
				else if (j==3) {
					cout << "Skladniki: ";
				}
				cout << Menu[i][j] << " ";
			}
			cout << "\n" << endl;
		}

		cout << "Aktualna wartosc koszyka: " << getCartValue() << " zl" << endl;

		cout << endl;

		cout << "[+]. Edytuj koszyk" << endl;
		cout << "[-]. Next step" << endl;

		cout << "Prosze wybrac danie lub akcje: ";
		cin >> id;

		if (id == "+") {
			editCart();
		}

		if (id != "-" && id != "+") {
			setQuantity(id);
		}

		if (id == "-" && cart_array.size() == 0) {
			system("cls");

			cout << "Musisz wybrac danie aby przejsc dalej" << endl;

			cin.get();
			cin.get();
		}

		if (id == "-" && cart_array.size() > 0) {
			break;
		}

	} while (true);
	
	checkout();
}