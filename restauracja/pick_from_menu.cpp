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
#include "print_cart_items.h"

using namespace std;

vector<Order> cart_array;

void addProductToCart(string index, int quantity) {
	//get item data form menu
	Order* newOrder = searchForItemInMenu(index, quantity);

	if (newOrder == NULL) {
		system("cls");

		cout << "W menu nie znaleziono dania o podanym numerze" << endl;
		cin.get();
		cin.get();
	}
	else {
		bool isItemInCart = false;

		//check if picked item is in cart
		for (int i = 0; i < cart_array.size(); i++) {
			if (cart_array[i].id == newOrder->id) {
				cart_array[i].quantity += quantity;
				isItemInCart = true;
			}
		}

		//if picked item is not in cart add it to it
		if (newOrder != NULL && !isItemInCart) {
			cart_array.push_back(Order(newOrder->id, newOrder->name, newOrder->price, newOrder->quantity));
		}
	}
}

void removeFromCart(string index) {
	int prevCartSize = cart_array.size();

	if (prevCartSize == 0) {
		system("cls");

		cout << "Koszyk jest pusty" << endl;

		cin.get();
		cin.get();

	}
	else {

		stringstream ss(index);
		int strAsInt;
		ss >> strAsInt;

		if (strAsInt > 0) {
			cart_array.erase(cart_array.begin() + (strAsInt - 1));
		}

		//if item is not delete handle error
		if (prevCartSize == cart_array.size()) {
			system("cls");

			cout << "Produktu o podanym identyfikatorze nie ma w koszyku" << endl;
			cin.get();
			cin.get();
		}
	}
}

void editCart() {
	string index_of_an_item;

	do {
		system("cls");

		cout << "Koszyk: " << endl;
		printCartItems();

		cout << "[-]. Wroc" << endl;

		cout << "Wybierz element do usuniecia lub akcje: ";
		cin >> index_of_an_item;

		if (index_of_an_item != "-") {
			removeFromCart(index_of_an_item);
		}
	} while (index_of_an_item != "-");
}

void setQuantity(string index) {
	int quantity = 0;

	do {
		system("cls");

		cout <<"Podaj ilosc porcji: ";
		cin >> quantity;

		if(quantity > 0) {
			addProductToCart(index, quantity);
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

		//print menu items
		fstream file("menu.csv");
		if (file.is_open())
		{
			int index = 1;
			while (getline(file, line))
			{
				row.clear();

				std::stringstream str(line);

				row.push_back(to_string(index) + ".");

				int word_number = 0;
				while (getline(str, word, ';')) {
					if (word_number != 0) {
						row.push_back(word);
					}
					word_number++;
				}
				Menu.push_back(row);

				index++;
			}
		}
		//add external description before price and ingredients
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
		cout << "[-]. Podsumowanie zamowienia" << endl;

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

		//if user want to go to next step check if is he having some items in cart
		if (id == "-" && cart_array.size() > 0) {
			break;
		}

	} while (true);
	
	checkout();
}