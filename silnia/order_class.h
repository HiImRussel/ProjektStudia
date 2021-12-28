#ifndef ORDER_CLASS_H
#define ORDER_CLASS_H

#include <string>

using namespace std;

class Order
{
public:
    string id;
    string name;
    float price;
    int quanity;

    Order(string id, string name, float price, int quantity) {
        this->id = id;
        this->name = name;
        this->price = price;
        this->quanity = quantity;
    }
};

#endif
