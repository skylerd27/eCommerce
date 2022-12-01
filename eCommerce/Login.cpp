/*login.cpp */

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string username;
    string password;
    string email;
    string phoneNumber;

    map<string, string> users;

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

    return 0;
}
