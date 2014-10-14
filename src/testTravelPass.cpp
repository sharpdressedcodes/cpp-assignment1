/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment #1 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

// testTravelPass.cpp for CPT 323 Assignment 1 SP3 2014
//
//
// CPT323 2014  assignment 1

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

	/*
	 * Task C4 - uncomment to check.
	 */
	//TwoHoursZone1 thz1;
	//cin >> thz1;
	//cout << thz1;

	return EXIT_SUCCESS;

}
