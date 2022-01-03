#include <iostream>
#include "get_cart_value.h"
#include "global_variables.h"

float getCartValue() {
	float total_cart_value = 0;

	for (int i = 0; i < cart_array.size();i++) {
		total_cart_value += cart_array[i].price * cart_array[i].quantity;
	}

	return total_cart_value;
}