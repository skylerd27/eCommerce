/*login.cpp */

#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void login();
void register();

int main()
{
int choice;
cout << " *******LOGIN*******"
cout << "1.Login";
cout << "\n2.Register";
cout << "\nEnter your choice:";
cin >> choice;

 switch(choice)
 {
    case 1:
    login();
    break;
    case 2:
    register();
    case 3:
    cout << "Thanks for Login in\n ";
    break;
    default:
    cout << "Please proceed to the next step"
    main();
 }
}
void register()
{
    string ruser,rpass;
    system("cls");
    cout << "Enter the username:";
    cin>>rguser
    cout << "Enter the password:";
    cin>>rpass
}