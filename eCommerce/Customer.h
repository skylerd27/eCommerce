#pragma once
#include <string>
#include <vector>
#include "ShoppingCart.h"
#include "Global.h"

using namespace std;

class Customer {
    private:
        int ID;
        string name;
        string phone;
        string email;
        string password;
        string address;
        string payment;
        vector<string> history;
    public:
        Customer(const string& name="", const string& phone="", const string& email="", const string& password="",
                    const string& address="", const string& payment="", const vector<string>& history={});
        ~Customer();
        void setName(const string& name);
        void setPhone(const string& phone);
        void setEmail(const string& email);
        void setPassword(const string& password);
        void setAddress(const string& address);
        void setPayment(const string& payment);
        void setHistory(const vector<string>& history);
        string getName();
        string getPhone();
        string getEmail();
        string getPassword();
        string getAddress();
        string getPayment();
        vector<string> getHistory();
        ShoppingCart cart;
};