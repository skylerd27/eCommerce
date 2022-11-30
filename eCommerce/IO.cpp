//This will read the csv file in the folder
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//Filepath set to .csv file in folder
	string myFilePath = "cl.csv";
	ifstream Hardware; //input file
	ofstream OHardware; //output file

	//opens input file
	Hardware.open(myFilePath);
	//opens output file
	OHardware.open("output.csv");

	//read from input
	while (Hardware.peek() != EOF) {
		string records;
		getline(Hardware, records, ',');

		cout << records << endl;
	}
	//close input and output
	Hardware.close();
	OHardware.close();

	return 0;
}