#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>


using namespace std;


string users_data_filename = "users_data.txt";


void print_users_data() {
	ifstream file;
	file.open(users_data_filename.data());
	string name1, name2, book;
	while (getline(file, name1, ';')) {
		getline(file, name2, ';');
		getline(file, book, ';');
		cout << name1 << " " << name2 << " " << book << "\n";
		getline(file, name1, '\n');
	}
}


int32_t main(){
	ofstream file;
	file.open(users_data_filename.data(), ios_base::app);
	cout << "Hellow, user! We need some data about you." << "\n";
	string name1, name2, book;
	cout << "First name: ";
	cin >> name1;
	cout << "Second name: ";
	cin >> name2;
	cout << "Your favorite book: ";
	cin >> book;
	file << name1 << ";" << name2 << ";" << book << ";\n";
	file.close();
	return 0;
}
