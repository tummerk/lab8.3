#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int N_Max = 2000;
string vowels = "aeoyui";

void read(string words[N_Max],int& i) {
	std::ifstream in("input.txt");
	while (!in.eof()) {
		in >> words[i];
		i++;
	}
}

string clearWord(string word) {
	string s = word;
	for (int i = 0; i < s.length(); i++) {
		if (!isalpha(s[i])) {
			s.erase(i, 1);
			i--;
		}
	}return s;
}

bool isVow(char ch){
	for (int i = 0; i < 6; i++) {
		if (ch == vowels[i]) {
			return true;
		}
	}return false;
}

bool uniq(string vow,char ch) {
	for (int i = 0; i < vow.length(); i++) {
		if (vow[i] == ch)
			return false;
	}return true;
}

string recurVowels(string word) {
	string vowels = "";
	for (int i = 0; i < word.length(); i++) {
		if (isVow(word[i]) && word[i] == word[i + 1] && uniq(vowels,word[i])){
			vowels += word[i];
			i++;
		}
	}return vowels;
}

string bracket(string vow){
	string s = "(";
	for (int i = 0; i < vow.length(); i++) {
		s += vow[i];
	}s += ')';
	return s;
}

string up(string word){ 
	string s=" ";
	for (int i = 0; i < word.length(); i++) {
		s += toupper(word[i]);
	}return s;
}

int lastLet(string word) {
	for (int i = 0; i < word.length()-1; i++){
		if (!isalpha(word[i]) && word[i]!='-')
			return i - 1;
	}return word.length();
}


void processing(string word[N_Max]) {

}

void main() {
	std::string words[N_Max];
	int i = 0;
	string word = "auoi";
	cout << bracket(word);
}