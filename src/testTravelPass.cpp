// testTravelPass.cpp for CPT 323 Assignment 1 SP3 2009
//
//
// CPT323 2010  assignment 1

#include "testTravelPass.h"

/////////////////////////////////////////////////////
int main(){

	//Create MyTic object and use this object in the menu
	MyTic tic(MAX_TRAVELPASSES);
	UI::mainMenu options;
	UI::subMenu timeOptions;
	UI::subMenu zoneOptions;

	UI::instance()->loadMenu(options);
	UI::instance()->loadTimeMenu(timeOptions);
	UI::instance()->loadZoneMenu(zoneOptions);
   
	UI::instance()->enterMenu(tic, options, timeOptions, zoneOptions);

	UI::instance()->deleteMenu(options);
	UI::instance()->deleteTimeMenu(timeOptions);
	UI::instance()->deleteZoneMenu(zoneOptions);

	return 0;

}
