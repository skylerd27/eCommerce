#include "Inventory.h"
#include "Item.h"

Inventory::Inventory(const map<Item*, int>& stock, const int& revenue)
{
    this->stock = stock;
    this->revenue = revenue;
}

float Inventory::getRevenue() { return revenue; }
void Inventory::setRevenue(const float& revenue) { this->revenue = revenue; }

bool Inventory::add(const string& name, const int& quantity, const float& price)
{
    // similar to add function for shoppingcart, starting with searching within stock for the item
    for (map<Item*, int>::iterator iter = stock.begin(); iter != stock.end(); iter++) {
        // if found, we simply add to the preexisting quantity in stock
        if (iter->first->getName() == name) {
            iter->second += quantity;
            return true;
        }
    }
    // else, create new item and insert it into stock
    // if price is not provided for new item return false
    if (price == -1) return false;
    Item newItem(name, price);
    Item* temp = &newItem;
    stock.insert({temp, quantity});
    return true;
}

bool Inventory::remove(const string& name, const int& quantity)
{
    // look for item in stock
    for (map<Item*, int>::iterator iter = stock.begin(); iter != stock.end(); iter++) {
        // if found, we check if there is enough to remove
        if (iter->first->getName() == name) {
            if (iter->second < quantity) return false;
            iter->second -= quantity;
            return true;
        }
    }
}
