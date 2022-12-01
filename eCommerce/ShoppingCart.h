#pragma once
#include <string>
#include "Item.h"
#include "Inventory.h"
#include "Global.h"
#include <map>
#include <iterator>

using namespace std;

class ShoppingCart {
    private:
        int ID;
        Inventory* shelf;
        map<Item*, int> items;
    public:
        ShoppingCart(const map<Item*, int>& items={});
        ~ShoppingCart();
        int getID();
        bool display(ostream& os);
        bool add(const string& name, const int& quantity=1);
        bool remove(const string& name, const int& quantity=1);
        void checkOut();
        bool setShelf(Inventory* shelf);
        int getShelfID();
};