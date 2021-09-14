#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;


/*
Navalny is the best!
*/


int32_t main(){
	ofstream file;
	file.open("users_data.txt", ios_base::app);
	cout << "Hellow, user! We need some data about you." << "\n";
	string name1, name2, book, party;
	cout << "First name: ";
	getline(cin, name1, '\n');
	cout << "Second name: ";
	getline(cin, name2, '\n');
	cout << "Your favorite book: ";
	getline(cin, book, '\n');
	cout << "Which party will you vote for: ";
	getline(cin, party, '\n');
	file << name1 << " " << name2 << " '" << book << "' '" << party << "'\n";
	file.close();
	return 0;
}
