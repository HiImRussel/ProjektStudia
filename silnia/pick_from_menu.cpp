#include <iostream>
#include <string>
#include "checkout.h"
#include <fstream>
#include "split_string_by_separator.h"
#include <vector>
#include "order_class.h"
#include <sstream>

using namespace std;


/*void addProductToCart(string id) {
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
			if (Menu[i][0] == id) {
				cout << Menu[i][0] << Menu[i][1] << Menu[i][2] << 1 << endl;
			}
			
		}
		cout << "\n" << endl;
	}
}
*/

void pickFromMenu() {
	//string id;
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

	   //vector<string> splitedArray = splitString(line, ';');
	
	   
	   //cout << "Proszê wybrac danie: " << endl;
	   //cin >> id;
	   //addProductToCart(id);

	
	
	//Order newOrder(0,"name_of_order",7.55,1);

	//cout << "new order name:"<< newOrder.name;

	checkout();
}