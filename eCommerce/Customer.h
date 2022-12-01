#pragma once
#include <string>
#include <vector>
#include "ShoppingCart.h"

using namespace std;

class Customer {
    private:
        string name;
        string phone;
        string email;
        string password;
        string address;
        string payment;
        string last;
    public:
        Customer(const string& name="", const string& phone="", const string& email="", const string& password="",
                    const string& address="", const string& payment="", const string& last="");
        void setName(const string& name);
        void setPhone(const string& phone);
        void setEmail(const string& email);
        void setPassword(const string& password);
        void setAddress(const string& address);
        void setPayment(const string& payment);
        void checkOut();
        string getName();
        string getPhone();
        string getEmail();
        string getPassword();
        string getAddress();
        string getPayment();
        string getLast();
        ShoppingCart cart;
};