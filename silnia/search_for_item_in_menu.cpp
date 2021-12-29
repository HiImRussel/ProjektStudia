#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

#include "checkout.h"
#include "split_string_by_separator.h"
#include "order_class.h"
#include "global_variables.h"
#include "order_class.h"

using namespace std;

Order* searchForItemInMenu(string id, int quantity) {
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

				return new Order(product_id, name, price, product_quantity);
			}
		}
	}

	return NULL;
}