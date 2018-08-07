#ifndef HIGHLIGHT
#define HIGHLIGHT

//just use hightlight_para (string name_of_the_file.txt, int position_of_the_paragraph, string input_query)

#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <Windows.h>
#include <cstring>

int Nword(string text);						//return the number of individual word inside text
string* query_arr(string text);				//make an array out of individual word from text
void color_print(string &text);				//print the word in color
void normalize(string &text);				//lower case the word + remove punctuation
void to_lower(string &text);			
void remove_puctuation(string &word);		
bool is_qry(string* queries, int n, string word);							//check if a word is == query							
void highLightQueries(string *queries, int n, string text);					//highlight queries in the text
void hightlight_para(string file_name, int para, string queries);			//highlight the all the queries in a paragraph (para th) from file_name.txt
#endif // !HIGHLIGHT

