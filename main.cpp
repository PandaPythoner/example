#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>


using namespace std;


int32_t main(){
	ofstream file;
	file.open("users_data.txt", ios_base::app);
	cout << "Hellow, user! We need some data about you." << "\n";
	string name1, name2, book;
	cout << "First name: ";
	cin >> name1;
	cout << "Second name: ";
	cin >> name2;
	cout << "Your favorite book: ";
	cin >> book;
	file << name1 << " " << name2 << " " << book << "\n";
	file.close();
	return 0;
}
