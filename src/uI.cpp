/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment #1 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "uI.h"

UI *UI::m_instance = NULL;

string UI::MENU_STRING_QUIT = "Quit";
string UI::MENU_STRING_BUY = "Buy a travel pass";
string UI::MENU_STRING_CHARGE = "Charge my MyTic";
string UI::MENU_STRING_SHOW = "Show remaining credit";
string UI::MENU_STRING_PRINT = "Print purchases";
string UI::MENU_STRING_CANCEL = "Cancel";

string UI::CREDIT_PREFIX = "Your credit = $";
string UI::YOU_PURCHASED_PREFIX = "You purchased ";
string UI::PURCHASED_PREFIX = "Purchased ";
string UI::PURCHASES_PREFIX = "\nPurchases: ($";
string UI::PURCHASES_SUFFIX = ")\n";

string UI::MESSAGE_CANNOT_ADD_CREDIT = "You cannot add anymore credit!";
string UI::MESSAGE_ADD_CREDIT = "How much do you want to add: ";
string UI::MESSAGE_CREDIT_OVER = "Sorry, the maximum allowed credit is $";
string UI::MESSAGE_CREDIT_DIVISOR = "Sorry, you can only add multiples of $";
string UI::MESSAGE_NOT_ENOUGH_CREDIT = "Sorry, you don't have enough credit for that selection.";
string UI::MESSAGE_NO_PURCHASES = "No purchases found.\n\n";
string UI::MESSAGE_NO_CREDIT = "You don't have any credit!";
string UI::MESSAGE_MAX_PASSES = "You have reached the maximum number of Travel Passes";
string UI::MESSAGE_MENU_WELCOME = "Welcome to MyTic!";
string UI::MESSAGE_MENU_OPTION = "Choose an option:";
string UI::MESSAGE_MENU_SELECTION = "Please make a selection: ";
string UI::MESSAGE_MENU_INVALID_SELECTION = "Sorry, that is an invalid option!";
string UI::MESSAGE_MENU_GOODBYE = "Goodbye!";
string UI::MESSAGE_MENU_TIME_PERIOD = "\nWhat time period:";
string UI::MESSAGE_MENU_YOUR_SELECTION = "Your selection: ";
string UI::MESSAGE_MENU_ZONE = "\nWhich zone:";

UI *UI::instance(){

	if (!m_instance)
		m_instance = new UI();

	return m_instance;

}

void UI::loadMenu(mainMenu& options){

	int i = 0;

	for (i = 0; i < MAX_MENU; i++)
		options.push_back(new UI::menuOptions<int>());

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

	options[i]->index = MENU_INDEX_PRINT;
	options[i++]->text = MENU_STRING_PRINT;

}

void UI::loadTimeMenu(subMenu& timeOptions){

	int i = 0;

	for (i = 0; i < MAX_MENU_TIME; i++)
		timeOptions.push_back(new UI::menuOptions<char>());

	i = 0;

	timeOptions[i]->index = MENU_INDEX_TIME_2HOURS;
	timeOptions[i++]->text = TwoHoursZone1::DEFAULT_LENGTH;

	timeOptions[i]->index = MENU_INDEX_TIME_DAY;
	timeOptions[i++]->text = AllDayZone1::DEFAULT_LENGTH;

	timeOptions[i]->isQuit = true;
	timeOptions[i]->index = MENU_INDEX_TIME_CANCEL;
	timeOptions[i++]->text = MENU_STRING_CANCEL;

}

void UI::loadZoneMenu(subMenu& zoneOptions){

	int i = 0;

	for (i = 0; i < MAX_MENU_ZONE; i++)
		zoneOptions.push_back(new UI::menuOptions<char>());

	i = 0;

	zoneOptions[i]->index = MENU_INDEX_ZONE_1;
	zoneOptions[i++]->text = AllDayZone1::DEFAULT_ZONES;

	zoneOptions[i]->index = MENU_INDEX_ZONE_1AND2;
	zoneOptions[i++]->text = AllDayZone1And2::DEFAULT_ZONES;

	zoneOptions[i]->isQuit = true;
	zoneOptions[i]->index = MENU_INDEX_ZONE_CANCEL;
	zoneOptions[i++]->text = MENU_STRING_CANCEL;

}

void UI::deleteMenu(mainMenu& options){

	for (mainMenu::iterator it = options.begin(); it != options.end(); ++it){
		mainMenuOption option = (*it);
		delete option;
	}

}

void UI::deleteTimeMenu(subMenu& timeOptions){

	for (subMenu::iterator it = timeOptions.begin(); it != timeOptions.end(); ++it){
		subMenuOption option = (*it);
		delete option;
	}

}

void UI::deleteZoneMenu(subMenu& zoneOptions){

	for (subMenu::iterator it = zoneOptions.begin(); it != zoneOptions.end(); ++it){
		subMenuOption option = (*it);
		delete option;
	}

}

void UI::showCredit(const MyTic& tic) {

	cout << CREDIT_PREFIX << Utility::floatToString(tic.getCredit(), 2) << "\n\n";

}

void UI::addCredit(MyTic& tic){

	bool chargeValid = false;
	int charge = 0;

	while (!chargeValid){
		if (tic.getCredit() >= tic.getLimit()){
			cerr << MESSAGE_CANNOT_ADD_CREDIT << endl;
			break;
		}

		stringstream ss;
		ss << MESSAGE_CREDIT_OVER << Utility::floatToString((float)tic.getLimit(), 2);
		charge = Utility::getIntFromConsole(0, tic.getLimit(), MESSAGE_ADD_CREDIT, ss.str(), false);

		if (charge > 0){
			if (tic.getCredit() + charge > tic.getLimit()){
				cerr << ss.str() << endl;
			} else if (charge % MyTic::AMOUNT_DIVISOR != 0){
				cerr << MESSAGE_CREDIT_DIVISOR << Utility::floatToString((float)MyTic::AMOUNT_DIVISOR, 2) << endl;
			} else {
				chargeValid = true;
				tic.addCredit(charge);
			}
		}
	}

}

bool UI::buyTicket(MyTic& tic, subMenu timeOptions, subMenu zoneOptions){

	bool result = false;
	subMenuOption timeOption = NULL;
	subMenuOption zoneOption = NULL;

	if (tic.getCredit() == 0){
		cerr << MESSAGE_NO_CREDIT << endl;
		return false;
	}

	timeOption = enterTimeMenu(timeOptions);

	if (timeOption != NULL){
		zoneOption = enterZoneMenu(zoneOptions);

		if (zoneOption != NULL){

			TravelPass *pass = assignTravelPass(timeOption, zoneOption);
			if (pass != NULL){

				float cost = pass->getCost();

				if (cost > tic.getCredit()){
					cerr << MESSAGE_NOT_ENOUGH_CREDIT << endl;
				} else {
					if (tic.buyPass(pass)){
						cout << YOU_PURCHASED_PREFIX;
						pass->print();
						showCredit(tic);
					} else {
						cerr << MESSAGE_MAX_PASSES << endl;
					}
				}

			}

		}
	}

	return result;

}

void UI::printPurchases(MyTic& tic){

	vector<TravelPass*> purchases = tic.getPurchases();

	cout << PURCHASES_PREFIX << Utility::floatToString(tic.getPurchaseTotal(), 2) << PURCHASES_SUFFIX;

	if (purchases.size() > 0){
		for (vector<TravelPass*>::const_iterator it = purchases.begin(); it != purchases.end(); ++it){
			cout << PURCHASED_PREFIX;
			(*it)->print();
		}
		cout << endl;
	} else {
		cout << MESSAGE_NO_PURCHASES;
	}

}

void UI::enterMenu(MyTic& tic, mainMenu options, subMenu timeOptions, subMenu zoneOptions){

	bool hasQuit = false;

	cout << MESSAGE_MENU_WELCOME << endl;

	while (!hasQuit) {

		mainMenuOption quitOption = NULL;

		cout << MESSAGE_MENU_OPTION << endl;

		for (mainMenu::iterator it = options.begin(); it != options.end(); ++it){
			mainMenuOption option = (*it);
			if (!option->isQuit)
				cout << option->index << ". " << option->text << endl;
			else
				quitOption = option;
		}

		if (quitOption)
			cout << quitOption->index << ". " << quitOption->text << endl;

		int selection = Utility::getIntFromConsole(MENU_INDEX_QUIT, MAX_MENU - 1, MESSAGE_MENU_SELECTION, MESSAGE_MENU_INVALID_SELECTION, false);

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

		case MENU_INDEX_PRINT:

			printPurchases(tic);
			break;

		case MENU_INDEX_QUIT:

			hasQuit = true;
			break;

		}

	}

	tic.clearPurchases();
	cout << MESSAGE_MENU_GOODBYE << endl;

}

UI::subMenuOption UI::enterTimeMenu(subMenu timeOptions){

	bool hasQuit = false;

	while (!hasQuit){

		subMenuOption quitOption = NULL;

		cout << MESSAGE_MENU_TIME_PERIOD << endl;

		for (subMenu::iterator it = timeOptions.begin(); it != timeOptions.end(); ++it){
			subMenuOption option = (*it);
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
			selection = Utility::getStringFromConsole(1, 1, MESSAGE_MENU_YOUR_SELECTION, MESSAGE_MENU_INVALID_SELECTION, false);
			if (!selection.empty())
				validSelection = validateTimeOption(selection[0], timeOptions);
			if (!validSelection)
				cerr << MESSAGE_MENU_INVALID_SELECTION << endl;
		} while (!validSelection);

		switch (selection[0]){

		case MENU_INDEX_TIME_2HOURS:

			return timeOptions[0];

		case MENU_INDEX_TIME_DAY:

			return timeOptions[1];

		case MENU_INDEX_TIME_CANCEL:

			hasQuit = true;
			break;

		}

	}

	return NULL;

}

UI::subMenuOption UI::enterZoneMenu(subMenu zoneOptions){

	bool hasQuit = false;

	while (!hasQuit){

		subMenuOption quitOption = NULL;

		cout << MESSAGE_MENU_ZONE << endl;

		for (subMenu::iterator it = zoneOptions.begin(); it != zoneOptions.end(); ++it){
			subMenuOption option = (*it);
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
			selection = Utility::getStringFromConsole(1, 1, MESSAGE_MENU_YOUR_SELECTION, MESSAGE_MENU_INVALID_SELECTION, false);
			if (!selection.empty())
				validSelection = validateZoneOption(selection[0], zoneOptions);
			if (!validSelection)
				cerr << MESSAGE_MENU_INVALID_SELECTION << endl;
		} while (!validSelection);

		switch (selection[0]){

		case MENU_INDEX_ZONE_1:

			return zoneOptions[0];

		case MENU_INDEX_ZONE_1AND2:

			return zoneOptions[1];

		case MENU_INDEX_ZONE_CANCEL:

			hasQuit = true;
			break;

		}

	}

	return NULL;

}

bool UI::validateTimeOption(const char option, subMenu timeOptions){

	bool result = false;

	for (subMenu::iterator it = timeOptions.begin(); it != timeOptions.end(); ++it){
		if ((*it)->index == option){
			result = true;
			break;
		}
	}

	return result;

}

bool UI::validateZoneOption(const char option, subMenu zoneOptions){

	bool result = false;

	for (subMenu::iterator it = zoneOptions.begin(); it != zoneOptions.end(); ++it){
		if ((*it)->index == option){
			result = true;
			break;
		}
	}

	return result;

}

TravelPass* UI::assignTravelPass(subMenuOption timeOption, subMenuOption zoneOption){

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
