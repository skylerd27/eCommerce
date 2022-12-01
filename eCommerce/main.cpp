/*login.cpp */

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include "Customer.h"
#include "Item.h"
#include "Inventory.h"  
#include "ShoppingCart.h"
#include <sstream>
#include <iterator>

using namespace std;

vector<Customer> loadCustomers()
{
    vector<Customer> allCustomers;
    stringstream ss;
    string line;
    string name, phone, email, password, address, payment, last;

	//Filepath set to .csv file in folder
	ifstream fin; //input file

	//opens input file
	fin.open("Customers.csv");
    if (!fin.is_open()) throw runtime_error("Could not open file");

    while (getline(fin, line)) {
        ss.clear();
        ss.str(line);
        getline(ss, name, ',');
        getline(ss, phone, ',');
        getline(ss, email, ',');
        getline(ss, password, ',');
        getline(ss, address, ',');
        getline(ss, payment, ',');
        getline(ss, last, ',');
        Item temp(name, phone, email, password, address, payment, last);
        allItems.push_back(temp);
    }
    fin.close();
    return allCustomers;
}

vector<Inventory> loadInventories()
{
   vector<Inventory> allInventories;
    stringstream ss;
    string name;
	//Filepath set to .csv file in folder
	ifstream fin; //input file

	//opens input file
	fin.open("Inventories.csv");
    if (!fin.is_open()) throw runtime_error("Could not open file");

    while (getline(fin, line)) {
        float revenue;
        map<Item*, int> tempMap;
        ss.clear();
        ss.str(line);
        ss >> revenue;
        ss.ignore();
        while (getline(ss, name, ',')) {
            float price;
            int quantity;
            ss >> price;
            ss.ignore();
            ss >> quantity;
            ss.ignore();
            Item temp(name, price);
            Item* tempPTR = &temp;
            tempMap.insert({tempPTR, price});
        }
        allInventories.push_back(tempMap, revenue);
    }
    fin.close();
    return allInventories;
}

void login() {

    cout << "Welcome to E-commerce Store!" << endl;
    cout << "Login and Register to use Store" << endl;

    while (true) {
        cout << "Please choose one of the following options: " << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;

        int option;
        cin >> option;

        if (option == 1) {
            // Login
            cout << "Please enter your username: ";
            cin >> username;

            if (users.count(username) > 0) {
                cout << "Please enter your password: ";
                cin >> password;

                if (users[username] == password) {
                    cout << "You have successfully logged in!" << endl;
                }
                else {
                    cout << "Incorrect password!" << endl;
                }
            }
            else {
                cout << "This username does not exist!" << endl;
            }
        }
        else if (option == 2) {
            // Register
            cout << "Please enter a username: ";
            cin >> username;

            if (users.count(username) > 0) {
                cout << "This username already exists!" << endl;
            }
            else {
                cout << "Please enter a password: ";
                cin >> password;

                cout << "Please enter your email: ";
                cin >> email;

                cout << "Please enter your phone number: ";
                cin >> phoneNumber;

                users[username] = password;
                cout << "You have successfully registered!" << endl;
            }
        }
        else if (option == 3) {
            // Exit
            break;
        }
        else {
            cout << "Invalid option!" << endl;
        }
    }
}

// ADD MENU FUNCTION HERE


void outputData(vector<Customer>& allCustomers, vector<Inventory>& allInventories) {
    ofstream fout;
    fout.open("Customers.csv");
    if(!fout.is_open()) throw runtime_error("Could not open file");
    for (Customer& i : allCustomers) {
        fout << i.getName() << ',' << i.getPhone() << ',' << i.getEmail() << ',' << i.getPassword() << ',' << i.getAddress() << ',' << i.getPayment() << ',' << i.getLast() << ",\n";
    }
    fout.close();
    fout.open("Inventories.csv");
    if(!fout.is_open()) throw runtime_error("Could not open file");
    for (Inventory& i : allInventories) {
        fout << i.getRevenue() << ',';
        for (map<Item*, int>::iterator iter = i.stock.begin(); i != i.stock.end(); i++) {
            fout << iter->first->getName() << ',' << iter->first->getPrice() << ',' << iter->second << ',';
        }
        cout << '\n';
    }
    fout.close();
}

int main() {
    loadData();
}
