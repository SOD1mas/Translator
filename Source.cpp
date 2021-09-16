#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

ifstream en_in;
ifstream ru_in;
ifstream num_in;
ofstream en_out;
ofstream ru_out;
ofstream num_out;

int main() {
	string word;
	bool language;
	cout << "English to Russian(0) or Russian to English(1)" << endl;
	cin >> language;
	cout << "Input your word" << endl;
	cin >> word;
	num_in.open("Nums.txt");
	int num;
	num_in >> num;
	num_in.close();
	vector<string> en_words(num);
	vector<string> ru_words(num);
	for (int i = 0; i < num; i++) {
		en_in.open("En_Words.txt");
		ru_in.open("Ru_Words.txt");
		en_in >> en_words[i];
		ru_in >> ru_words[i];
	}
	bool insert = false;
	if (!language) {
		for (int i = 0; i < num; i++) {
			if (en_words[i] == word) {
				cout << ru_words[i] << endl;
				return 0;
			}
		}
		insert = true;
	}
	else {
		for (int i = 0; i < num; i++) {
			if (ru_words[i] == word) {
				cout << en_words[i] << endl;
				return 0;
			}
		}
		insert = true;
	}
	if (insert) {
		cout << "Your word is not there. Add it? 1(yes) or 0(no)" << endl;
		bool insert1;
		cin >> insert1;
		cout << "Input English word and Russian word" << endl;
		string ru_word, en_word;
		cin >> en_word >> ru_word;
		en_out.open("En_Words.txt", ios::app);
		ru_out.open("Ru_Words.txt", ios::app);
		num_out.open("Nums.txt");
		num_out << num + 1;
		en_out << en_word << endl;
		ru_out << ru_word << endl;
		en_out.close();
		ru_out.close();
		num_out.close();
	}
}