#include <iostream>
#include <string>
#include "global_variables.h"

using namespace std;

void checkout() {
	for (int i = 0;i < cart_array.size();i++) {
		cout << cart_array[i].name << " " << cart_array[i].quantity << endl;
	}
}