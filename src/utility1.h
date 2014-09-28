//
// utility1.h
//
// This header file contains utility  functions
//

#ifndef __UTILITY1_H__
#define __UTILITY1_H__

#include <string>
#include <iostream>

/*
// gk
#include <cstdlib>
#include <sstream>
#include <vector>
*/


using std::string;
using namespace std;

/*//gk
using std::vector;*/

/*struct menuOptions {
	int index;
	string text;
	bool isQuit;
};*/

/*
#define MAX_MENU 4
#define MENU_INDEX_QUIT 0
#define MENU_INDEX_BUY 1
#define MENU_INDEX_CHARGE 2
#define MENU_INDEX_SHOW 3
#define MENU_STRING_QUIT "Quit"
#define MENU_STRING_BUY "Buy a travel pass"
#define MENU_STRING_CHARGE "Charge my MyTic"
#define MENU_STRING_SHOW "Show remaining credit"
*/

void clearInputBuffer();

// gk
/*void loadMenu(vector<menuOptions*>& options);
void deleteMenu(vector<menuOptions*>& options);
int getIntFromConsole(int min, int max, string message, string errorMessage, bool allowEmpty);
string getStringFromConsole(int min, int max, string message, string errorMessage, bool allowEmpty);
int stringToInt(const string& str);
string intToString(const int number);*/




#endif
