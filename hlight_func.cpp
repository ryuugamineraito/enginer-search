#include "Highlight.h"
int Nword(string text) {
	int n = 0; int l = text.length();
	while (!text.empty()) {
		int loc = text.find(" ");
		if (loc < 0 || loc>l)return n + 1;
		text.erase(0, loc + 1);
		n++;
	}
	return n;
}

string* query_arr(string text) {
	//number of individual word inside text
	int n = Nword(text);
	//make an array of individual words in the query
	string* arr = new string[n];
	int i = 0; int l = text.length();

	while (!text.empty()) {
		int loc = text.find(" ");
		//if a word is found in the query loc = location
		if (loc < l&&loc>0) {
			arr[i++] = text.substr(0, loc);
			normalize(arr[i - 1]);//remove puctuation and lower all case
			text.erase(0, loc + 1);
		}
		else {
			normalize(text);
			arr[i++] = text;
			text = "";//erase all of text
		}
	}
	return arr;
}

void color_print(string &text) {
	//print the word but not the associated punctuation
	string punct;
	if (ispunct(text[text.size() - 1])) {
		punct = text[text.size() - 1];
		text.erase(text.size() - 1, 1);
	}
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 2);
	cout << text;
	SetConsoleTextAttribute(h, 15);
	if (!punct.empty())cout << punct;//print the punctuation seperately
}

void to_lower(string &text) {
	int n = text.size();
	for (int i = 0; i < n; i++)
		text[i] = tolower(text[i]);
}
void remove_puctuation(string &word) {
	int last_char = word.size() - 1;
	if (ispunct(word[last_char]))word.erase(last_char, 1);
}
void normalize(string &text) {
	to_lower(text);
	remove_puctuation(text);
}

bool is_qry(string* queries, int n, string word) {
	normalize(word);
	for (int i = 0; i < n; i++)if (word == queries[i]) return true;
	return false;
}

void highLightQueries(string *queries, int n, string text) {
	unsigned int sz = text.size();
	while (!text.empty()) {
		//if a word can not be found inside text
		if (text.find(" ") < 0 || text.find(" ") > sz) {
			if (is_qry(queries, n, text)) color_print(text);
			else cout << text;
			cout << endl;
			return;
		}
		string word = text.substr(0, text.find(" "));
		if (is_qry(queries, n, word)) {
			color_print(word);
			cout << " ";
		}
		else cout << word << " ";
		text.erase(0, text.find(" ") + 1);
	}
}

void hightlight_para(string file_name, int para, string query) {
	string*queries = query_arr(query);
	int n = Nword(query);
	int pos = 1;
	string text;
	ifstream read(file_name);
	if (!read.is_open())cout << "ERROR: CANT OPEN FILE";
	//while not end of file, we still be able to getline into text
	while (getline(read, text)) {
		//at correct position
		if (pos == para) {
			highLightQueries(queries, n, text);
			while (text != "") {
				if (getline(read, text)) highLightQueries(queries, n, text);
				else return;
			}
			return;
		}
		//move to correct position
		if (text == "")pos++;
	}
	read.close();
}