#include <iostream>
#include <string>
#include "checkout.h"
#include <fstream>
#include "split_string_by_separator.h"
#include <vector>
#include "order_class.h"
#include <sstream>
#include "global_variables.h"
#include "order_class.h"

using namespace std;


vector<Order> cart_array;

void addProductToCart(string id, int quantity) {
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

			while (getline(str, word, ','))
				row.push_back(word);
			Menu.push_back(row);
		}
	}
	bool is_item_found = false;
	for (int i = 0; i < Menu.size(); i++)
	{
		for (int j = 0; j < Menu[i].size(); j++)
		{
			if (Menu[i][0] == id && !is_item_found) {
				string product_id = Menu[i][0];
				string name = Menu[i][1];
				float price = stof(Menu[i][2]);
				int product_quantity = quantity;

				is_item_found = true;

				cart_array.push_back(Order(product_id, name, price, product_quantity));
			}
		}
		cout << "\n" << endl;
	}

	if (!is_item_found) {
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

	cart_array.erase(cart_array.begin() + (strAsInt - 1));

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
				cout << i+1 << ". " << "Danie: " << cart_array[i].name << "  Ilosc porcji:  " << cart_array[i].quantity << " Cena: " << cart_array[i].price * cart_array[i].quantity << endl;
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

				while (getline(str, word, ','))
					row.push_back(word);
				Menu.push_back(row);
			}
		}
		for (int i = 0; i < Menu.size(); i++)
		{
			for (int j = 0; j < Menu[i].size(); j++)
			{
				cout << Menu[i][j] << " ";
			}
			cout << "\n" << endl;
		}

		cout << "[+]. Edytuj koszyk" << endl;
		cout << "[-]. Next step" << endl;

		cout << "Prosze wybrac danie: ";
		cin >> id;

		if (id == "+") {
			editCart();
		}
		if (id != "-" && id != "+") {
			setQuantity(id);
		}
	} while (id != "-");


	//Order newOrder(0,"name_of_order",7.55,1);

	//cout << "new order name:"<< newOrder.name;
	
	checkout();
}