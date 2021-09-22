#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <set>


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


void print_users_data(int sorting_index = 0, int interesting_index = 2) {
	ifstream file;
	file.open(users_data_filename.data());
	vector<vector<string> > answers;
	string s;
	while (getline(file, s, ';')) {
		answers.push_back(vector<string>());
		for (int i = 0; i < asks.size(); ++i) {
			answers.back().push_back(s);
			if (i != asks.size() - 1) {
				getline(file, s, ';');
			}
		}
		getline(file, s, '\n');
	}
	sort(answers.begin(), answers.end(), [sorting_index](const vector<string>& a, const vector<string>& b) {
		return a[sorting_index] < b[sorting_index];
	});
	set<string> interesting;
	for (auto& a : answers) {
		for (auto& s : a) {
			cout << "'" << s << "' ";
		}
		cout << "\n";
		interesting.insert(a[interesting_index]);
	}
	cout << "Statistics: " << "\n";
	cout << "Users: " << answers.size() << "\n";
	cout << "Books: " << interesting.size() << "\n";
}



void ask_user_data() {
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
}


void change_questions() {
    ofstream file;
    string s = "";
    cout << "Do you want to delete old asks(Y/N)?" << "\n";
    getline(cin, s);
    if(s == "Y")
        file.open(asks_data_filename.data());
    else
        file.open(asks_data_filename.data(), ofstream::app);
	cout << "Enter number of new asks:" << "\n";
	int num;
	cin >> num;
	if(num > 0)
        cout << "Enter your asks:" << "\n";
    getline(cin, s);//cin and getline don't like each other
	for (int i = 0; i < num; ++i) {
		getline(cin, s);
		file << s << "\n";
	}
	file.close();
}


int32_t main() {
	get_asks();
	cout << "Do you want to see other users data(Y/N)?" << "\n";
	string s = "";
	while (s != "Y" && s != "N") {
		getline(cin, s);
	}
	if (s == "Y") {
		print_users_data();
	}
	else {
        cout << "Do you want to change asks(Y/N)?" << "\n";
        getline(cin, s);
        if(s == "Y")
            change_questions();
        else
            ask_user_data();
	}
	return 0;
}
