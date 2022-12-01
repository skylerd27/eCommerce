#include "Customer.h"

Customer::Customer(const string& name="", const string& phone="", const string& email="", const string& password="",
                    const string& address="", const string& payment="", const vector<string>& history={})
{
    ID = objectCount[0]++;
    this->name = name;
    this->phone = phone;
    this->email = email;
    this->password = password;
    this->address = address;
    this->payment = payment;
    this->history = history;
}

Customer::~Customer()
{
    objectCount[0]--;
}

void Customer::setName(const string& name) { this->name = name; }
void Customer::setPhone(const string& phone) { this->phone = phone; }
void Customer::setEmail(const string& email) { this->email = email; }
void Customer::setPassword(const string& password) { this->password = password; }
void Customer::setAddress(const string& address) { this->address = address; }
void Customer::setPayment(const string& payment) { this->payment = payment; }
void Customer::setHistory(const vector<string>& history) { this->history = history; }

string Customer::getName() { return name; }
string Customer::getPhone() { return phone; }
string Customer::getEmail() { return email; }
string Customer::getPassword() { return password; }
string Customer::getAddress() { return address; }
string Customer::getPayment() { return payment; }
vector<string> Customer::getHistory() { return history; }