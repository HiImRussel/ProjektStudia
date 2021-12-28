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
	bool stoper = false;
	for (int i = 0; i < Menu.size(); i++)
	{
		for (int j = 0; j < Menu[i].size(); j++)
		{
			if (Menu[i][0] == id && !stoper) {
				string product_id = Menu[i][0];
				string name = Menu[i][1];
				float price = stof(Menu[i][2]);
				int product_quantity = quantity;

				stoper = true;

				cart_array.push_back(Order(product_id, name, price, product_quantity));
			}
		}
		cout << "\n" << endl;
	}
}

void setQuantity(string id) {
	int quanity;
	do {
		cout <<"Podaj ilosc porcji : "<<endl;
		cin >> quanity;

		if(quanity > 0) {
			addProductToCart(id, quanity);
		}
		else {
			system("cls");
			cout << "Ilosc musi byc wieksza od 0" << endl;
		}
	} while (quanity <= 0);
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

		cout << "[0]. Next step" << endl;

		cout << "Prosze wybrac danie: " << endl;
		cin >> id;

		if (id != "0") {
			setQuantity(id);
		}

	} while (id != "0");;


	//Order newOrder(0,"name_of_order",7.55,1);

	//cout << "new order name:"<< newOrder.name;

	checkout();
}