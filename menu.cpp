#include <iostream>
#include <string>
#include "Login.cpp"
using namespace std;

// Before Login
void beforeLogin()
{
	cout << "1- Login" << endl;
	cout << "2- Create Account" << endl;
	cout << "3- Quit" << endl;
}

// After Login
void afterLogin()
{
	cout << "1- Logout" << endl;
	cout << "2- Quit" << endl;
	cout << "3- View Hardware" << endl;
	cout << "4- View Account Information" << endl;
	cout << " 5- View Order History" << endl;
	cout << "6- Edit Account information" << endl;
	cout << "   7- Checkout" << endl;

}

int main()
{
	bool isLoggedIn = false;
	
	while(true){
		if(!isLoggedIn){
			beforeLogin();
			
			int choice;
			cin >> choice;
			
			if(choice == 1){
				cout << "Logging in..." << endl;
				isLoggedIn = true;
			} else if(choice == 2){
				cout << "Creating account..." << endl;
				isLoggedIn = true;
			} else if(choice == 3){
				break;
			} else {
				cout << "Invalid choice" << endl;
			}
			
		} else {
			afterLogin();
			
			int choice;
			cin >> choice;
			
			if(choice == 1){
				cout << "Logging out..." << endl;
				isLoggedIn = false;
			} else if(choice == 2){
				break;
			} else if(choice == 3){
				cout << "Viewing Hardware..." << endl;
			} else if(choice == 4){
				cout << "Viewing Account Information..." << endl;
			} else if(choice == 5){
				cout << "Editing Account Information..." << endl;
			} else if(choice == 6){
				cout << "Checkout..." <<endl;
			}
			} else {
				cout << "Invalid choice" << endl;
			}
		}
	}
	
	return 0;
}
