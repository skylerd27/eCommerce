#pragma once
#include <string>
#include "Global.h"

using namespace std;

class Item {
    private:
        int ID;
        string name;
        float price;
    public:
        Item(const string& name="",  const float& price=0);
        ~Item();
        int getID();
        string getName();
        float getPrice();
        void setName(const string& name);
        void setPrice(const float& price);
};