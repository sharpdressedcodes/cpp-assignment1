// testTravelPass.cpp for CPT 323 Assignment 1 SP3 2009
//
//
// CPT323 2010  assignment 1



#include "testTravelPass.h"

// gk
#include <cstdlib>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>

//gk
using std::vector;

template <typename T>
struct menuOptions {
	T index;
	string text;
	bool isQuit;
};

/*struct menuOptions {
	int index;
	string text;
	bool isQuit;
};

struct subMenuOptions {
	char index;
	string text;
	bool isQuit;
};*/

#define MAX_MENU 4
#define MENU_INDEX_QUIT 0
#define MENU_INDEX_BUY 1
#define MENU_INDEX_CHARGE 2
#define MENU_INDEX_SHOW 3
#define MENU_STRING_QUIT "Quit"
#define MENU_STRING_BUY "Buy a travel pass"
#define MENU_STRING_CHARGE "Charge my MyTic"
#define MENU_STRING_SHOW "Show remaining credit"

#define MAX_MENU_TIME 3
#define MENU_INDEX_TIME_2HOURS 'a'
#define MENU_INDEX_TIME_DAY 'b'
#define MENU_INDEX_TIME_CANCEL 'c'
#define MENU_STRING_TIME_2HOURS "2 Hours"
#define MENU_STRING_TIME_DAY "All Day"
#define MENU_STRING_TIME_CANCEL "Cancel"

#define MAX_MENU_ZONE 3
#define MENU_INDEX_ZONE_1 'a'
#define MENU_INDEX_ZONE_1AND2 'b'
#define MENU_INDEX_ZONE_CANCEL 'c'
#define MENU_STRING_ZONE_1 "Zone 1"
#define MENU_STRING_ZONE_1AND2 "Zones 1 and 2"
#define MENU_STRING_ZONE_CANCEL "Cancel"


void loadMenu(vector<menuOptions<int>*>& options);
void loadTimeMenu(vector<menuOptions<char>*>& timeOptions);
void loadZoneMenu(vector<menuOptions<char>*>& zoneOptions);
void deleteMenu(vector<menuOptions<int>*>& options);
void deleteTimeMenu(vector<menuOptions<char>*>& timeOptions);
void deleteZoneMenu(vector<menuOptions<char>*>& zoneOptions);
int getIntFromConsole(const unsigned int min, const unsigned int max, const string message, const string errorMessage, bool allowEmpty);
string getStringFromConsole(const unsigned int min, const unsigned int max, const string message, const string errorMessage, bool allowEmpty);
int stringToInt(const string str);
string intToString(const int number);
string floatToString(const float number, const int precision);

void enterMenu(MyTic& tic, vector<menuOptions<int>*> options, vector<menuOptions<char>*> timeOptions, vector<menuOptions<char>*> zoneOptions);
menuOptions<char>* enterTimeMenu(MyTic& tic, vector<menuOptions<char>*> timeOptions);
menuOptions<char>* enterZoneMenu(MyTic& tic, vector<menuOptions<char>*> zoneOptions);
void showCredit(const MyTic tic);
void addCredit(MyTic& tic);
bool buyTicket(MyTic& tic, vector<menuOptions<char>*> timeOptions, vector<menuOptions<char>*> zoneOptions);
bool validateTimeOption(const char option, vector<menuOptions<char>*> timeOptions);
bool validateZoneOption(const char option, vector<menuOptions<char>*> zoneOptions);
TravelPass* assignTravelPass(menuOptions<char>* timeOption, menuOptions<char>* zoneOption);

void loadMenu(vector<menuOptions<int>*>& options){

	int i = 0;

	for (i = 0; i < MAX_MENU; i++)
		options.push_back(new menuOptions<int>());

	i = 0;

	options[i]->isQuit = true;
	options[i]->index = MENU_INDEX_QUIT;
	options[i++]->text = MENU_STRING_QUIT;

	options[i]->index = MENU_INDEX_BUY;
	options[i++]->text = MENU_STRING_BUY;

	options[i]->index = MENU_INDEX_CHARGE;
	options[i++]->text = MENU_STRING_CHARGE;

	options[i]->index = MENU_INDEX_SHOW;
	options[i++]->text = MENU_STRING_SHOW;

}

void loadTimeMenu(vector<menuOptions<char>*>& timeOptions){

	int i = 0;

	for (i = 0; i < MAX_MENU_TIME; i++)
		timeOptions.push_back(new menuOptions<char>());

	i = 0;

	timeOptions[i]->index = MENU_INDEX_TIME_2HOURS;
	timeOptions[i++]->text = MENU_STRING_TIME_2HOURS;

	timeOptions[i]->index = MENU_INDEX_TIME_DAY;
	timeOptions[i++]->text = MENU_STRING_TIME_DAY;

	timeOptions[i]->isQuit = true;
	timeOptions[i]->index = MENU_INDEX_TIME_CANCEL;
	timeOptions[i++]->text = MENU_STRING_TIME_CANCEL;

}

void loadZoneMenu(vector<menuOptions<char>*>& zoneOptions){

	int i = 0;

	for (i = 0; i < MAX_MENU_ZONE; i++)
		zoneOptions.push_back(new menuOptions<char>());

	i = 0;

	zoneOptions[i]->index = MENU_INDEX_ZONE_1;
	zoneOptions[i++]->text = MENU_STRING_ZONE_1;

	zoneOptions[i]->index = MENU_INDEX_ZONE_1AND2;
	zoneOptions[i++]->text = MENU_STRING_ZONE_1AND2;

	zoneOptions[i]->isQuit = true;
	zoneOptions[i]->index = MENU_INDEX_ZONE_CANCEL;
	zoneOptions[i++]->text = MENU_STRING_ZONE_CANCEL;

}

void deleteMenu(vector<menuOptions<int>*>& options){

	for (vector<menuOptions<int>*>::iterator it = options.begin(); it != options.end(); ++it){
		menuOptions<int>* option = (*it);
		delete option;
	}

	/*for (int i = 0; i < MAX_MENU; i++)
		delete options[i];*/

}

void deleteTimeMenu(vector<menuOptions<char>*>& timeOptions){

	for (vector<menuOptions<char>*>::iterator it = timeOptions.begin(); it != timeOptions.end(); ++it){
		menuOptions<char>* option = (*it);
		delete option;
	}

}

void deleteZoneMenu(vector<menuOptions<char>*>& zoneOptions){

	for (vector<menuOptions<char>*>::iterator it = zoneOptions.begin(); it != zoneOptions.end(); ++it){
		menuOptions<char>* option = (*it);
		delete option;
	}

}

int getIntFromConsole(const unsigned int min, const unsigned int max, const string message, const string errorMessage, bool allowEmpty = true){

	int i = -1;
	bool isValid = false;

	while (!isValid){

		string result;

		cout << message;
		getline(cin, result);

		if (cin.fail()){
			if (!allowEmpty)
				cerr << errorMessage << endl;
			clearInputBuffer();
		} else {
			i = stringToInt(result);

			if ((unsigned int)i < min || (unsigned int)i > max){
				if (allowEmpty)
					return min - 1;
				cerr << errorMessage << endl;
			} else {
				isValid = true;
			}
		}

	}

	return i;

}

string getStringFromConsole(const unsigned int min, const unsigned int max, const string message, const string errorMessage, bool allowEmpty = true){

	bool isValid = false;
	string result;

	while (!isValid){

		cout << message;
		getline(cin, result);

		if (result.length() < min || result.length() > max){
			if (allowEmpty)
				return "";
			cerr << errorMessage << endl;
		} else {
			isValid = true;

		}

	}

	return result;

}

int stringToInt(const string str){

	int result = (int)std::atol(str.c_str());

	return result;

}

string intToString(const int number){

	std::ostringstream ss;
	ss << number;

	return ss.str();

}

string floatToString(const float number, const int precision = -1){

	std::ostringstream ss;

	//if (precision > -1){
		//ss << std::fixed << std::setprecision(precision);
		//ss << std::setprecision(2) << std::fixed;
		//ss << std::fixed;// << std::showpoint;
		//ss << std::setprecision(2);
		//ss << std::setprecision(2);
	//}


	//double d = (double)3.1434;
	//ss << std::showpoint << number;
	ss << number;
	//ss << std::setprecision(2);

	return ss.str();

}

void showCredit(const MyTic tic) {

	float credit = tic.getCredit();

	if (credit == 0){
		cout << "Your credit = $0.00\n\n";
	} else {

		cout.setf(std::ios::fixed);
		cout.setf(std::ios::showpoint);
		cout.precision(2);

		cout << "Your credit = $" << credit << "\n\n";
	}

}

void addCredit(MyTic& tic){

	bool chargeValid = false;
	int charge = 0;

	while (!chargeValid){
		charge = getIntFromConsole(0, tic.getLimit(), "How much do you want to add: ", "Invalid amount", false);
		if (charge > 0){
			if (tic.getCredit() + charge > tic.getLimit()){
				cerr << "Sorry, the maximum allowed credit is $" << intToString(tic.getLimit()) << ".00\n";
			} else if (charge % MyTic::AMOUNT_DIVISOR != 0){
				cerr << "Sorry, you can only add multiples of $" << intToString(MyTic::AMOUNT_DIVISOR) << ".00\n";
			} else {
				chargeValid = true;
				tic.addCredit(charge);
			}
		}
	}

}

bool buyTicket(MyTic& tic, vector<menuOptions<char>*> timeOptions, vector<menuOptions<char>*> zoneOptions){

	bool result = false;
	menuOptions<char>* timeOption = NULL;
	menuOptions<char>* zoneOption = NULL;

	timeOption = enterTimeMenu(tic, timeOptions);

	if (timeOption != NULL){
		zoneOption = enterZoneMenu(tic, zoneOptions);
		if (zoneOption != NULL){
			TravelPass *pass = assignTravelPass(timeOption, zoneOption);
			if (pass != NULL){

				// TODO: finish this off.

				float cost = pass->getCost();

				if (cost > tic.getCredit()){
					cerr << "Sorry, you don't have enough credit for that selection.\n";
				} else {
					tic.addCredit(-cost);
					cout << "You purchased " << timeOption->text << " pass for " << zoneOption->text << ", costing $" << floatToString(cost, 2) << endl;
					showCredit(tic);

				}

			}

		}
	}

	return result;

}


void enterMenu(MyTic& tic, vector<menuOptions<int>*> options, vector<menuOptions<char>*> timeOptions, vector<menuOptions<char>*> zoneOptions){

	bool hasQuit = false;

	cout << "Welcome to MyTic!\n";

	while (!hasQuit) {

		menuOptions<int>* quitOption = NULL;

		cout << "Choose an option:\n";

		for (vector<menuOptions<int>*>::iterator it = options.begin(); it != options.end(); ++it){
			menuOptions<int>* option = (*it);
			if (!option->isQuit)
				cout << option->index << ". " << option->text << endl;
			else
				quitOption = option;
		}

		if (quitOption)
			cout << quitOption->index << ". " << quitOption->text << endl;

		int selection = getIntFromConsole(0, MAX_MENU, "Please make a selection: ", "Sorry, that is an invalid option!", false);

		switch (selection){

		case MENU_INDEX_BUY:

			buyTicket(tic, timeOptions, zoneOptions);
			break;

		case MENU_INDEX_CHARGE:

			addCredit(tic);
			showCredit(tic);
			break;

		case MENU_INDEX_SHOW:

			showCredit(tic);
			break;

		case MENU_INDEX_QUIT:

			hasQuit = true;
			break;

		}

	}

	cout << "Goodbye!\n";

}

menuOptions<char>* enterTimeMenu(MyTic& tic, vector<menuOptions<char>*> timeOptions){

	bool hasQuit = false;

	while (!hasQuit){

		menuOptions<char>* quitOption = NULL;

		cout << "\nWhat time period:\n";

		for (vector<menuOptions<char>*>::iterator it = timeOptions.begin(); it != timeOptions.end(); ++it){
			menuOptions<char>* option = (*it);
			if (!option->isQuit)
				cout << option->index << ") " << option->text << endl;
			else
				quitOption = option;
		}

		if (quitOption)
			cout << quitOption->index << ") " << quitOption->text << endl;

		string selection;
		bool validSelection = true;

		do {
			validSelection = false;
			selection = getStringFromConsole(1, 1, "Your selection: ", "Sorry, that is an invalid option!", false);
			if (!selection.empty())
				validSelection = validateTimeOption(selection[0], timeOptions);
			if (!validSelection)
				cerr << "Sorry, that is an invalid option!\n";
		} while (!validSelection);

		switch (selection[0]){

		case MENU_INDEX_TIME_2HOURS:


			//break;
			return timeOptions[0];

		case MENU_INDEX_TIME_DAY:


			//break;
			return timeOptions[1];

		case MENU_INDEX_TIME_CANCEL:

			hasQuit = true;
			break;

		}

	}

	//return hasQuit ? false : true;
	return NULL;

}

menuOptions<char>* enterZoneMenu(MyTic& tic, vector<menuOptions<char>*> zoneOptions){

	bool hasQuit = false;

	while (!hasQuit){

		menuOptions<char>* quitOption = NULL;

		cout << "\nWhich zone:\n";

		for (vector<menuOptions<char>*>::iterator it = zoneOptions.begin(); it != zoneOptions.end(); ++it){
			menuOptions<char>* option = (*it);
			if (!option->isQuit)
				cout << option->index << ") " << option->text << endl;
			else
				quitOption = option;
		}

		if (quitOption)
			cout << quitOption->index << ") " << quitOption->text << endl;

		string selection;
		bool validSelection = true;

		do {
			validSelection = false;
			selection = getStringFromConsole(1, 1, "Your selection: ", "Sorry, that is an invalid option!", false);
			if (!selection.empty())
				validSelection = validateZoneOption(selection[0], zoneOptions);
			if (!validSelection)
				cerr << "Sorry, that is an invalid option!\n";
		} while (!validSelection);

		switch (selection[0]){

		case MENU_INDEX_ZONE_1:


			//break;
			return zoneOptions[0];

		case MENU_INDEX_ZONE_1AND2:


			//break;
			return zoneOptions[1];

		case MENU_INDEX_ZONE_CANCEL:

			hasQuit = true;
			break;

		}

	}

	//return hasQuit ? false : true;
	return NULL;

}

bool validateTimeOption(const char option, vector<menuOptions<char>*> timeOptions){

	bool result = false;

	for (vector<menuOptions<char>*>::iterator it = timeOptions.begin(); it != timeOptions.end(); ++it){
		if ((*it)->index == option){
			result = true;
			break;
		}
	}

	return result;

}

bool validateZoneOption(const char option, vector<menuOptions<char>*> zoneOptions){

	bool result = false;

	for (vector<menuOptions<char>*>::iterator it = zoneOptions.begin(); it != zoneOptions.end(); ++it){
		if ((*it)->index == option){
			result = true;
			break;
		}
	}

	return result;

}

TravelPass* assignTravelPass(menuOptions<char>* timeOption, menuOptions<char>* zoneOption){

	TravelPass* pass = NULL;

	switch (timeOption->index){
	case MENU_INDEX_TIME_2HOURS:
		switch (zoneOption->index){
		case MENU_INDEX_ZONE_1:
			pass = new TwoHoursZone1();
			break;
		case MENU_INDEX_ZONE_1AND2:
			pass = new TwoHoursZone1And2();
			break;
		}
		break;
	case MENU_INDEX_TIME_DAY:
		switch (zoneOption->index){
		case MENU_INDEX_ZONE_1:
			pass = new AllDayZone1();
			break;
		case MENU_INDEX_ZONE_1AND2:
			pass = new AllDayZone1And2();
			break;
		}
		break;
	}

	return pass;

}

/////////////////////////////////////////////////////
int main(){

	//Create MyTic object and use this object in the menu
	MyTic tic;
	vector<menuOptions<int>*> options;
	vector<menuOptions<char>*> timeOptions;
	vector<menuOptions<char>*> zoneOptions;

	loadMenu(options);
	loadTimeMenu(timeOptions);
	loadZoneMenu(zoneOptions);
   
	enterMenu(tic, options, timeOptions, zoneOptions);

	deleteMenu(options);
	deleteTimeMenu(timeOptions);
	deleteZoneMenu(zoneOptions);

	return 0;

}
