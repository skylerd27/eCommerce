#pragma once
#include <string>
#include <map>
#include "Item.h"

using namespace std;

class Inventory {
    private:
        float revenue;
    public:
        Inventory(const map<Item*, int>& stock={}, const float& revenue=0);
        bool add(const string& name, const int& quantity=1, const float& price=-1);
        bool remove(const string& name, const int& quantity=1);
        float getRevenue();
        void setRevenue(const float& revenue);
        map<Item*, int> stock;
};