#include"UI.h"
#include"Header.h"
#include<cstring>
// UI test zone


void start()
{
	system("CLS");
	cout << "if the file is not loaded then load it in, else dont (remove this line later nig)" << endl;
	// if (is_loaded) == false
	cout << "loading lul" << endl;
	// load file
	cout << "Search it up nigger: ";
	// input query
	cout << "What would you like to do next nigger" << endl;
	cout << "1. Search" << endl;
	cout << "2. History" << endl;
	int a; cin >> a;
	if (a == 1) search();
	else if (a == 2) history();
}

void end()
{
	system("CLS");
	// destroy
	cout << "System has ended." << endl;
}

void search()
{
	system("CLS");
	// execute searching
	cout << "Results found:" << endl;
	// show some shit here
	cout << "What would you like to do next" << endl;
	operate();
}

void history()
{
	system("CLS");
	cout << "Your history so far: " << endl;
	// show history
	cout << "What would you like to do next" << endl;
	operate();
}

void operate()
{
	cout << "1. Start" << endl;
	cout << "2. Exit" << endl;
	int a;
	cin >> a;
	if (a == 1) start();
	else if (a == 2) end();
}