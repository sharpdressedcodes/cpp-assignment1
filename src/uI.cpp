#include "uI.h"

UI *UI::m_instance = NULL;

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
	timeOptions[i++]->text = MENU_STRING_TIME_CANCEL;

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
	zoneOptions[i++]->text = MENU_STRING_ZONE_CANCEL;

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

void UI::showCredit(const MyTic tic) {

	cout << "Your credit = $" << Utility::floatToString(tic.getCredit(), 2) << "\n\n";

}

void UI::addCredit(MyTic& tic){

	bool chargeValid = false;
	int charge = 0;

	while (!chargeValid){
		if (tic.getCredit() >= tic.getLimit()){
			cerr << "You cannot add anymore credit!\n";
			break;
		}
		charge = Utility::getIntFromConsole(0, tic.getLimit(), "How much do you want to add: ", "Invalid amount", false);
		if (charge > 0){
			if (tic.getCredit() + charge > tic.getLimit()){
				cerr << "Sorry, the maximum allowed credit is $" << Utility::floatToString((float)tic.getLimit(), 2)  << "\n";
			} else if (charge % MyTic::AMOUNT_DIVISOR != 0){
				cerr << "Sorry, you can only add multiples of $" << Utility::floatToString((float)MyTic::AMOUNT_DIVISOR, 2) << "\n";
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

	timeOption = enterTimeMenu(tic, timeOptions);

	if (timeOption != NULL){
		zoneOption = enterZoneMenu(tic, zoneOptions);

		if (zoneOption != NULL){

			TravelPass *pass = assignTravelPass(timeOption, zoneOption);
			if (pass != NULL){

				float cost = pass->getCost();

				if (cost > tic.getCredit()){
					cerr << "Sorry, you don't have enough credit for that selection.\n";
				} else {
					tic.buyPass(pass);
					cout << "You purchased ";
					pass->print();
					showCredit(tic);

				}

			}

		}
	}

	return result;

}

void UI::printPurchases(MyTic& tic){

	vector<TravelPass*> purchases = tic.getPurchases();

	cout << "\nPurchases: ($" << Utility::floatToString(tic.getPurchaseTotal(), 2) << ")\n";

	if (purchases.size() > 0){
		for (vector<TravelPass*>::const_iterator it = purchases.begin(); it != purchases.end(); ++it){
			cout << "Purchased ";
			(*it)->print();
		}
		cout << endl;
	} else {
		cout << "No purchases found.\n\n";
	}

}

void UI::enterMenu(MyTic& tic, mainMenu options, subMenu timeOptions, subMenu zoneOptions){

	bool hasQuit = false;

	cout << "Welcome to MyTic!\n";

	while (!hasQuit) {

		mainMenuOption quitOption = NULL;

		cout << "Choose an option:\n";

		for (mainMenu::iterator it = options.begin(); it != options.end(); ++it){
			mainMenuOption option = (*it);
			if (!option->isQuit)
				cout << option->index << ". " << option->text << endl;
			else
				quitOption = option;
		}

		if (quitOption)
			cout << quitOption->index << ". " << quitOption->text << endl;

		int selection = Utility::getIntFromConsole(0, MAX_MENU, "Please make a selection: ", "Sorry, that is an invalid option!", false);

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

	cout << "Goodbye!\n";

}

UI::subMenuOption UI::enterTimeMenu(MyTic& tic, subMenu timeOptions){

	bool hasQuit = false;

	while (!hasQuit){

		subMenuOption quitOption = NULL;

		cout << "\nWhat time period:\n";

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
			selection = Utility::getStringFromConsole(1, 1, "Your selection: ", "Sorry, that is an invalid option!", false);
			if (!selection.empty())
				validSelection = validateTimeOption(selection[0], timeOptions);
			if (!validSelection)
				cerr << "Sorry, that is an invalid option!\n";
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

UI::subMenuOption UI::enterZoneMenu(MyTic& tic, subMenu zoneOptions){

	bool hasQuit = false;

	while (!hasQuit){

		subMenuOption quitOption = NULL;

		cout << "\nWhich zone:\n";

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
			selection = Utility::getStringFromConsole(1, 1, "Your selection: ", "Sorry, that is an invalid option!", false);
			if (!selection.empty())
				validSelection = validateZoneOption(selection[0], zoneOptions);
			if (!validSelection)
				cerr << "Sorry, that is an invalid option!\n";
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
