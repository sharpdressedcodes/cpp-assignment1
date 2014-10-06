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

#define MAX_MENU 5
#define MENU_INDEX_QUIT 0
#define MENU_INDEX_BUY 1
#define MENU_INDEX_CHARGE 2
#define MENU_INDEX_SHOW 3
#define MENU_INDEX_PRINT 4
#define MENU_STRING_QUIT "Quit"
#define MENU_STRING_BUY "Buy a travel pass"
#define MENU_STRING_CHARGE "Charge my MyTic"
#define MENU_STRING_SHOW "Show remaining credit"
#define MENU_STRING_PRINT "Print purchases"

#define MAX_MENU_TIME 3
#define MENU_INDEX_TIME_2HOURS 'a'
#define MENU_INDEX_TIME_DAY 'b'
#define MENU_INDEX_TIME_CANCEL 'c'
#define MENU_STRING_TIME_CANCEL "Cancel"

#define MAX_MENU_ZONE 3
#define MENU_INDEX_ZONE_1 'a'
#define MENU_INDEX_ZONE_1AND2 'b'
#define MENU_INDEX_ZONE_CANCEL 'c'
#define MENU_STRING_ZONE_CANCEL "Cancel"

class UI {

private:

	UI(){}
	UI(UI const&){}
	UI& operator=(UI const&);//{}
	static UI *m_instance;

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
	void enterMenu(MyTic& tic, mainMenu options, subMenu timeOptions, subMenu zoneOptions);
	subMenuOption enterTimeMenu(MyTic& tic, subMenu timeOptions);
	subMenuOption enterZoneMenu(MyTic& tic, subMenu zoneOptions);
	void showCredit(const MyTic tic);
	void addCredit(MyTic& tic);
	bool buyTicket(MyTic& tic, subMenu timeOptions, subMenu zoneOptions);
	void printPurchases(MyTic& tic);
	bool validateTimeOption(const char option, subMenu timeOptions);
	bool validateZoneOption(const char option, subMenu zoneOptions);
	TravelPass* assignTravelPass(subMenuOption timeOption, subMenuOption zoneOption);
};

#endif /* UI_H_ */
