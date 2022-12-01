#include "Item.h"

Item::Item(const string& name="", const float& price=0)
{
    ID = objectCount[2]++;
    this->name = name;
    this->price = price;
}

Item::~Item() 
{
    objectCount[2]--;
}

int Item::getID() { return ID; }
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