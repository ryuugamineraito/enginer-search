#include"Operator.h"
#include"Header.h"
#include"Highlight.h"

bool is_txt(string text) {
	int txt = text.find(":txt");
	if (txt <= 0 || txt>text.size())return false;
	if (text[txt - 1] == ' ')return false;
	else return true;
}

bool is_wildcard(string text) {
	int card = text.find("*");
	if (card<0 || card>text.size())return false;
	for (int i = 0; i < card; i++) if (text[i] != ' ')
		return true;
	for (int i = card + 1; i < text.size(); i++)
		if (text[i] != ' ')
			return true;
	return false;
}

bool is_currency(string text) {
	int money = text.find("$");
	if (money < 0 || money>text.size())return false;
	if (text.size() == money + 1)return false;
	if (isdigit(text[money + 1]))return true;
	else return false;
}

bool is_hashtag(string text) {
	int tag = text.find("#");
	if (tag < 0 || tag > text.size()) return false;
	if (text.size() == tag + 1)return false;
	if (text[tag + 1] != ' ')return true;
	else return false;
}

bool is_title(string text) {
	int tit = text.find("intitle:");
	if (tit != 0)return false;
	for (int i = tit + 8; i < text.size(); i++)
		if (text[i] != ' ')return true;
	return false;
}

bool is_exclude(string text) {
	bool fw = false;
	int excl = text.find("-");
	if (excl <= 0 || excl > text.size())return false;
	if (text[excl - 1] != ' ')return false;
	for (int i = 0; i < excl - 1; i++)
		if (text[i] != ' ') fw = true;
	for (int i = excl + 1; i < text.size() && fw == true; i++)
		if (text[i] != ' ') return true;
	return false;
}

bool is_OR(string text) {
	bool fw = false;//first word
	int And = -1;//or operator position
	for (int i = 0; i < text.size(); i++) {
		if (text[i] != ' ' && fw == false) {
			fw = true;
			And = text.find("OR", i + 1);
			if (And < 0 || And > text.size())return false;
			else {
				i += And +2;
				if (i > text.size())return false;
			}
		}
		if (And != -1 && text[i] != ' ')return true;
	}
	return false;
}