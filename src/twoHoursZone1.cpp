/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment #1 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "twoHoursZone1.h"

const float TwoHoursZone1::DEFAULT_PRICE = 2.5;
const string TwoHoursZone1::DEFAULT_LENGTH = "2 Hours";
const string TwoHoursZone1::DEFAULT_ZONES = "Zone 1";

TwoHoursZone1::TwoHoursZone1()
	: TravelPass(DEFAULT_LENGTH, DEFAULT_ZONES, DEFAULT_PRICE) {}

TwoHoursZone1::~TwoHoursZone1(){}

void TwoHoursZone1::input(){}

void TwoHoursZone1::print(){

	cout << this->toString();

}

bool TwoHoursZone1::isTravelPass(TravelPass& pUnknown){

	TwoHoursZone1* test = dynamic_cast<TwoHoursZone1*>(&pUnknown);

	if (test)
		return true;
	else
		return false;

}

string TwoHoursZone1::toString(){

	stringstream ss;

	ss << this->length << " pass for " << this->zones << ", costing $" << Utility::floatToString(this->cost, 2) << endl;

	return ss.str();

}

ostream& operator<<(ostream& stream, TwoHoursZone1& pass){

	stream << pass.toString();

	return stream;

}

istream& operator>>(istream& stream, TwoHoursZone1& pass){

	cout << "Enter length: ";
	stream >> pass.length;

	cout << "Enter zones: ";
	stream >> pass.zones;

	cout << "Enter cost: ";
	stream >> pass.cost;

	return stream;

}
