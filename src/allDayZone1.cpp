/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment #1 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "allDayZone1.h"

const float AllDayZone1::DEFAULT_PRICE = 4.9;
const string AllDayZone1::DEFAULT_LENGTH = "All Day";
const string AllDayZone1::DEFAULT_ZONES = "Zone 1";

AllDayZone1::AllDayZone1()
	: TravelPass(DEFAULT_LENGTH, DEFAULT_ZONES, DEFAULT_PRICE) {}

AllDayZone1::~AllDayZone1(){}

void AllDayZone1::input(){}

void AllDayZone1::print(){

	cout << this->toString();

}

bool AllDayZone1::isTravelPass(TravelPass& pUnknown){

	AllDayZone1* test = dynamic_cast<AllDayZone1*>(&pUnknown);

	if (test)
		return true;
	else
		return false;

}

string AllDayZone1::toString(){

	stringstream ss;

	ss << this->length << " pass for " << this->zones << ", costing $" << Utility::floatToString(this->cost, 2) << endl;

	return ss.str();

}

ostream& operator<<(ostream& stream, AllDayZone1& pass){

	stream << pass.toString();

	return stream;

}

istream& operator>>(istream& stream, AllDayZone1& pass){

	cout << "Enter length: ";
	stream >> pass.length;

	cout << "Enter zones: ";
	stream >> pass.zones;

	cout << "Enter cost: ";
	stream >> pass.cost;

	return stream;

}
