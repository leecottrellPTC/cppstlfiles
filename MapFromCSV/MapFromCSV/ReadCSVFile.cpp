// PracticeMap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include "Country.h"

using namespace std;
map<string, Country> countryMap;

void readFile(string theFile) {
	ifstream fin(theFile);
	string aLine;

	string delimiter = ",";
	string token;
	size_t pos = 0;
	int count = 0;

	if (fin.fail()) {
		cout << theFile << " did not open, quitting\n";
		exit(1);
	}

	while (!fin.eof()) {
		getline(fin, aLine);
		Country aCountry;
		while ((pos = aLine.find(delimiter)) != string::npos) {
			token = aLine.substr(0, pos);
			//cout << token << endl;
			aLine.erase(0, pos + delimiter.length());
			switch (count) {
			case 0:
				aCountry.setCode(token);
				break;
			case 1:
				aCountry.setLatitude(stod(token));//should try/catch this if you do not control file
				break;

			case 2:
				aCountry.setLongitude(stod(token));//should try/catch this if you do not control file
				break;
			default:
				//ignored in this logic
				break;
			}//end of switch
			count++;

		}//end while pos
		//cout << aLine << endl;//country is left after the loop
		aCountry.setName(aLine);
		count = 0;

		countryMap[aCountry.getCode()] = aCountry;
	
		//cout << aCountry << endl;
	}//end while fin

	fin.close();

	cout << countryMap.size() << " countries read from " << theFile << endl;
	

}//end readFile


int main()
{
	readFile("countries.csv");
	//cout << countryMap["XX"] << endl;

	string code="";
	while (code != "QUIT") {
		cout << "Enter a country code, 'QUIT' to exit ";
		cin >> code;
		cout << countryMap[code] << endl;
	}

	
	//cout << "File is opened\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
