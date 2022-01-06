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

Order* searchForItemInMenu(string index, int quantity) {
	vector<vector<string>> Menu;
	vector<string> row;
	string line, word;

	//open file that contains all item menu and add it to Menu vector
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
	int menu_size = Menu.size();

	//convert index to intiger
	stringstream ss(index);
	int strAsInt;
	ss >> strAsInt;

	strAsInt--;

	//if index is smaller than menu size or bigger than menu size return NULL
	if (strAsInt > menu_size-1 || strAsInt<0) return NULL;

	//create new Order from finded item
	string product_id = Menu[strAsInt][0];
	string name = Menu[strAsInt][1];
	float price = stof(Menu[strAsInt][2]);
	int product_quantity = quantity;

	return new Order(product_id, name, price, product_quantity);
}