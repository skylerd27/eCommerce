#include "ShoppingCart.h"
#include <iostream>

ShoppingCart::ShoppingCart(const map<Item*, int>& items={})
{
    ID = objectCount[3]++;
    this->items = items;
}

ShoppingCart::~ShoppingCart()
{
    objectCount[3]--;
}

int ShoppingCart::getID() { return ID; }

bool ShoppingCart::display(ostream& os)
{
    // output <name>, <quantity>, <price> to given ostream
    if (items.size() == 0) return false;
    for (map<Item*, int>::iterator iter = items.begin(); iter != items.end(); iter++) {
        os << iter->first->getName() << ", " << iter->second << ", " << iter->first->getPrice() << '\n';
    }
    return true;
}

bool ShoppingCart::add(const string& name, const int& quantity=1)
{
    // find item with given name in inventory (only works if name is unique)
    map<Item*, int>::iterator founditer, founditer2;
    bool found = false;
    for (map<Item*, int>::iterator iter = shelf->stock.begin(); iter != shelf->stock.end(); iter++) {
        if (iter->first->getName() == name) {
            founditer = iter;
            found = true;
            break;
        }
    }
    // if item is found and quantity available >= quantity requested, add it to items
    if (found == true) {
        if (founditer->second < quantity) return false;
        // look for item already in cart
        found = false;
        for (map<Item*, int>::iterator iter = items.begin(); iter != items.end(); iter++) {
            if (iter->first->getName() == name) {
                founditer2 = iter;
                found = true;
                break;
            }
        }
        // if found in cart, add to the quantity already in cart
        if (found == true) {
            if (founditer2->second + quantity > founditer->second) return false;
            founditer2->second += quantity;
        }
        // else, insert the item pointer into items
        else {
            items.insert({founditer->first, quantity});
        }
        return true;
    }
    // if not enough of requested item is available, return false
    return false;
}

bool ShoppingCart::remove(const string& name, const int& quantity=1)
{
    // find item with given name in cart
    map<Item*, int>::iterator founditer;
    bool found = false;
    for (map<Item*, int>::iterator iter = items.begin(); iter != items.end(); iter++) {
        if (iter->first->getName() == name) {
            founditer = iter;
            found = true;
            break;
        }
    }
    // if found and quantity in cart >= quantity to remove, remove specified # of item
    if (found == true) {
        if (founditer->second < quantity) return false;
        else if (founditer->second == quantity) items.erase(founditer);
        else founditer->second -= quantity;
        return true;
    }
    return false;
}

void ShoppingCart::checkOut() 
{
    for (map<Item*, int>::iterator iter = items.begin(); iter != items.end(); iter++) {
        shelf->stock.at(iter->first) -= iter->second;
        shelf->setRevenue(shelf->getRevenue() + iter->second * iter->first->getPrice());
    }
}

bool ShoppingCart::setShelf(Inventory* shelf)
{
    if (items.size() != 0) {
        this->shelf = shelf;
        return true;
    }
    return false;
}

int ShoppingCart::getShelfID()
{
    return shelf->getID();
}