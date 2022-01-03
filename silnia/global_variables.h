#include <string>
#include <vector>

#include "order_class.h"

using namespace std;

//order data
extern string user_name;
extern string user_surname;
extern int table_number;
extern int delivery_type; // 1 -> at restaurant location, 2 -> delivery to user
extern string delivery_hour;
extern string city;
extern string street;
extern string house_number;


//restaurant open hours varaible
extern string working_days_from;
extern string working_days_to;

extern string weekend_days_from;
extern string weekend_days_to;

//cart
extern vector<Order> cart_array;

//delivery time per dish
extern int making_time_per_dish;