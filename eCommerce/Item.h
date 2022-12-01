#pragma once
#include <string>

using namespace std;


class Item {
private:
    string name;
    float price;
public:
    Item(const string& name = "", const float& price = 0);
    string getName();
    float getPrice();
    void setName(const string& name);
    void setPrice(const float& price);
};