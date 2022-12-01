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
    if (!fin.is_open()) return {};
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
        Customer temp(name, phone, email, password, address, payment, last);
        allCustomers.push_back(temp);
    }
    fin.close();
    return allCustomers;
}

vector<Inventory> loadInventories()
{
    vector<Inventory> allInventories;
    string line;
    stringstream ss;
    string name;
	//Filepath set to .csv file in folder
	ifstream fin; //input file

	//opens input file
	fin.open("Inventories.csv");
    if (!fin.is_open()) return {};

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
        Inventory temp(tempMap, revenue);
        allInventories.push_back(temp);
    }
    fin.close();
    return allInventories;
}


string Login(vector<Customer>& allCustomers) {
    int choice = -1;
    cout << "E-Commerce Store Software System" << endl;
    while (true) {
        cout << "Login Menu\n\"1\" to log in\n\"2\" to create an account\n\"3\" to exit\n";
        cin >> choice;
        cout << '\n';
        if (choice == 1) {
            string username, guess;
            cout << "Enter name: ";
            cin >> username;
            for (vector<Customer>::iterator iter = allCustomers.begin(); iter != allCustomers.end(); iter++) {
                if (iter->getName() == username) {
                    cout << "Enter password\n";
                    while (true) {
                        cin >> guess;
                        if (guess == iter->getPassword()) {
                            cout << "Logging in...\n";
                            return username;
                        }
                    }
                    break;
                }
            }
        }
        else if (choice == 2) {
            string name, phone, email, password, address, payment, last;
            cout << "Enter name: ";
            cin >> name;
            // check for existing accound with same name
            bool found = false;
            for (vector<Customer>::iterator iter = allCustomers.begin(); iter != allCustomers.end(); iter++) {
                if (iter->getName() == name) {
                    found = true;
                    break;
                }
            }
            if (found == true) {
                cout << "Username already exists.\n";
                continue;
            }
            cout << "Enter phone number: ";
            cin >> phone;
            cout << "\nEnter email: ";
            cin >> email;
            cout << "\nEnter password: ";
            cin >> password;
            cout << "\nEnter address: ";
            cin >> address;
            cout << "\nEnter payment info: ";
            cin >> payment;
            Customer newGuy(name, phone, email, password, address, payment);
            allCustomers.push_back(newGuy);
            cout << "\nAccount created!\n";
        }
        else if (choice == 3) {
            cout << "Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid input. Please try again.\n";
        }
    }
    return "";
}

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
        for (map<Item*, int>::iterator iter = i.stock.begin(); iter != i.stock.end(); iter++) {
            fout << iter->first->getName() << ',' << iter->first->getPrice() << ',' << iter->second << ',';
        }
        cout << '\n';
    }
    fout.close();
}

void Menu(string loggedIn, vector<Customer> allCustomers, vector<Inventory> allInventories) {
    if (loggedIn == "admin") {
        while (true) {
            cout << "Admin Menu" << endl;
            cout << "Select number from list:" << endl;
            cout << "1. Manage customers\n2. Manage inventories\n";
            int option = -1;
            cin >> option;
            if (option == 1) {
                continue;
            }
            else if (option == 2) {
                cout << "Select number from list:" << endl;
                cout << "1. View inventories" << endl;
                cout << "2. Add inventory" << endl;
                cout << "3. Remove inventory" << endl;
                cout << "4. Edit inventory" << endl;
                cout << "5. Exit" << endl;
                cin >> option;
                if (option == 1) {
                    for (int i = 0; i < allInventories.size(); i++) {
                        cout << i + 1 << ": Revenue: " << allInventories.at(i).getRevenue() << endl;
                        for (map<Item*, int>::iterator iter = allInventories.at(i).stock.begin(); iter != allInventories.at(i).stock.end(); iter++) {
                            cout << "Items:\n";
                            cout << "Name: " << iter->first->getName() << endl;
                            cout << "Price: " << iter->first->getPrice() << endl;
                            cout << "Quantity: " << iter->second << endl;
                        }
                    }
                }
                else if (option == 2) {
                    cout << "Inventory added!\n";
                }
                else if (option == 3) {
                    cout << "Enter index of inventory to remove:\n";
                    int index = -1;
                    cin >> index;
                    if (!(index >= 0 && index < allInventories.size())) {
                        cout << "Invalid index\n";
                        continue;
                    }
                    else {
                        allInventories.erase(allInventories.begin() + index);
                        cout << "Inventory removed!\n";
                    }
                }
                else if (option == 4) {
                    continue;
                }
                else if (option == 5) {
                    continue;
                }
                else {
                    cout << "Invalid option" << endl;
                    continue;
                }
            }
            else if (option == 3) {
                break;
            }
            else {
                cout << "Invalid option\n";
            }
        }       
    }
    else {
        while (true) {
            cout << "Main Menu" << endl;
            cout << "Select number from list:" << endl;
            cout << "1. Shop" << endl;
            cout << "2. Account info" << endl;
            cout << "3. Exit" << endl;
            int option = -1;
            cin >> option;
            if (option == 1) {
                cout << "Choose store index (0 to " << allInventories.size() - 1 << "):\n";
                int index = -1;
                cin >> index;
                if (!(index >= 0 && index < allInventories.size())) {
                    cout << "Invalid index\n";
                    continue;
                }
                else {
                    vector<Customer>::iterator foundIter;
                    for (vector<Customer>::iterator iter = allCustomers.begin(); iter != allCustomers.end(); iter++) {
                        if (iter->getName() == loggedIn) {
                            foundIter = iter;
                            Inventory* tempPtr = &(allInventories.at(index));
                            iter->cart.setShelf(tempPtr);
                        }
                    }
                }
                cout << "Choose by number:\n";
                cout << "1. Add to cart" << endl;
                cout << "2. Remove from cart" << endl;
                cout << "3. Checkout" << endl;
                cin >> option;
                continue;
            }
            else if (option == 2) {
                continue;
            }
            else if (option == 3) {
                break;
            }
            else {
                cout << "Invalid option\n";
                continue;
            }
        }
    }
}

int main() {
    vector<Customer> allCustomers = loadCustomers();
    if (allCustomers.size() == 0) {
        Customer tempAdmin("admin", "", "", "admin");
        allCustomers.push_back(tempAdmin);
    }
    vector<Inventory> allInventories = loadInventories();
    if (allInventories.size() == 0) {
        Inventory firstStore;
        allInventories.push_back(firstStore);
    }
    string loggedIn = Login(allCustomers);
    if (loggedIn != "") {
        Menu(loggedIn, allCustomers, allInventories);
    }
}
