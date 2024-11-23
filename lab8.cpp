#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int N_Max = 5000;
string vowels = "aeoyui";

void read(string words[N_Max],int& cnt) {
	cnt = 0;
	std::ifstream in("input.txt");
	while (!in.eof()) {
		in >> words[cnt];
		cnt++;
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

string newWord(string word) {
	return up(word) + bracket(recurVowels(word));
}

void write(string word[N_Max],int cnt) {
	ofstream out("output.txt");
	for (int i = 0; i < cnt; i++) {
		if (recurVowels(word[i]) == "")
			out << word[i];
		else
			out << newWord(word[i]);
	}
}

void main() {
	std::string words[N_Max];
	int cnt;
	string word = "aaudgdfooi...";
	cout << newWord(word);
	read(words, cnt);
	write(words, cnt);
}
