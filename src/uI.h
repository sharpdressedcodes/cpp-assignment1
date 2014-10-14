/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment #1 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#ifndef UI_H_
#define UI_H_

#include "myTic.h"
#include "travelPass.h"
#include "twoHoursZone1.h"
#include "twoHoursZone1And2.h"
#include "allDayZone1.h"
#include "allDayZone1And2.h"
#include "utility.h"
#include <string>
#include <vector>

using namespace std;
using std::vector;

enum MENU_OPTIONS {
	MENU_INDEX_QUIT,
	MENU_INDEX_BUY,
	MENU_INDEX_CHARGE,
	MENU_INDEX_SHOW,
	MENU_INDEX_PRINT,
	MAX_MENU
};

enum MENU_TIME_OPTIONS {
	MENU_INDEX_TIME_2HOURS = 'a',
	MENU_INDEX_TIME_DAY = 'b',
	MENU_INDEX_TIME_CANCEL = 'c',
	MAX_MENU_TIME = 3
};

enum MENU_ZONE_OPTIONS {
	MENU_INDEX_ZONE_1 = 'a',
	MENU_INDEX_ZONE_1AND2 = 'b',
	MENU_INDEX_ZONE_CANCEL = 'c',
	MAX_MENU_ZONE = 3
};

class UI {

private:

	UI(){}
	UI(UI const&){}
	UI& operator=(UI const&);//{}
	static UI *m_instance;

	static string MENU_STRING_QUIT;
	static string MENU_STRING_BUY;
	static string MENU_STRING_CHARGE;
	static string MENU_STRING_SHOW;
	static string MENU_STRING_PRINT;
	static string MENU_STRING_CANCEL;

	static string CREDIT_PREFIX;
	static string YOU_PURCHASED_PREFIX;
	static string PURCHASED_PREFIX;
	static string PURCHASES_PREFIX;
	static string PURCHASES_SUFFIX;

	static string MESSAGE_CANNOT_ADD_CREDIT;
	static string MESSAGE_ADD_CREDIT;
	static string MESSAGE_CREDIT_OVER;
	static string MESSAGE_CREDIT_DIVISOR;
	static string MESSAGE_NOT_ENOUGH_CREDIT;
	static string MESSAGE_NO_PURCHASES;
	static string MESSAGE_NO_CREDIT;
	static string MESSAGE_MAX_PASSES;
	static string MESSAGE_MENU_WELCOME;
	static string MESSAGE_MENU_OPTION;
	static string MESSAGE_MENU_SELECTION;
	static string MESSAGE_MENU_INVALID_SELECTION;
	static string MESSAGE_MENU_GOODBYE;
	static string MESSAGE_MENU_TIME_PERIOD;
	static string MESSAGE_MENU_YOUR_SELECTION;
	static string MESSAGE_MENU_ZONE;

public:

	template <typename T>
	struct menuOptions {
		T index;
		string text;
		bool isQuit;
	};

	typedef UI::menuOptions<int>* mainMenuOption;
	typedef UI::menuOptions<char>* subMenuOption;
	typedef vector<mainMenuOption> mainMenu;
	typedef vector<subMenuOption> subMenu;

	static UI *instance();
	void loadMenu(mainMenu& options);
	void loadTimeMenu(subMenu& timeOptions);
	void loadZoneMenu(subMenu& zoneOptions);
	void deleteMenu(mainMenu& options);
	void deleteTimeMenu(subMenu& timeOptions);
	void deleteZoneMenu(subMenu& zoneOptions);
	void enterMenu(MyTic* tic, mainMenu options, subMenu timeOptions, subMenu zoneOptions);
	subMenuOption enterTimeMenu(subMenu timeOptions);
	subMenuOption enterZoneMenu(subMenu zoneOptions);
	void showCredit(const MyTic tic);
	void addCredit(MyTic* tic);
	bool buyTicket(MyTic* tic, subMenu timeOptions, subMenu zoneOptions);
	void printPurchases(MyTic* tic);
	bool validateTimeOption(const char option, subMenu timeOptions);
	bool validateZoneOption(const char option, subMenu zoneOptions);
	TravelPass* assignTravelPass(subMenuOption timeOption, subMenuOption zoneOption);

};

#endif /* UI_H_ */
