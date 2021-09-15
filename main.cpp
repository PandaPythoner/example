#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>


using namespace std;


string users_data_filename = "users_data.txt";
string asks_data_filename = "asks.txt";


vector<string> asks;


void get_asks() {
	ifstream file;
	file.open(asks_data_filename.data());
	string ask;
	asks.clear();
	while (getline(file, ask)) {
		asks.push_back(ask);
	}
}


int32_t main(){
	get_asks();
	ofstream file;
	file.open(users_data_filename.data(), ios_base::app);
	vector<string> answers(asks.size());
	for (int i = 0; i < asks.size(); ++i) {
		cout << asks[i];
		getline(cin, answers[i]);
		file << answers[i] << ';';
	}
	file << '\n';
	file.close();
	return 0;
}
