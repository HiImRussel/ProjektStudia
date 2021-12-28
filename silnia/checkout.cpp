#include <iostream>
#include <string>
#include "global_variables.h"

using namespace std;

void checkout() {
	system("cls");
	cout << "Koszyk: " << endl;
	for (int i = 0;i < cart_array.size();i++) {
		cout <<"Danie: " <<cart_array[i].name << ";  Ilosc porcji:  " << cart_array[i].quantity << endl;
	}
}