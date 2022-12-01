#include "Item.h"

Item::Item(const string& name, const float& price)
{
    this->name = name;
    this->price = price;
}

string Item::getName() { return name; }
float Item::getPrice() { return price; }

void Item::setName(const string& name)
{
    this->name = name;
}
void Item::setPrice(const float& price)
{
    this->price = price;
}