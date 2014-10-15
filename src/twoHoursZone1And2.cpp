/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment #1 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "twoHoursZone1And2.h"

const float TwoHoursZone1And2::DEFAULT_PRICE = 3.5;
const string TwoHoursZone1And2::DEFAULT_LENGTH = "2 Hours";
const string TwoHoursZone1And2::DEFAULT_ZONES = "Zones 1 and 2";

TwoHoursZone1And2::TwoHoursZone1And2()
	: TravelPass(DEFAULT_LENGTH, DEFAULT_ZONES, DEFAULT_PRICE) {}

TwoHoursZone1And2::~TwoHoursZone1And2(){}

void TwoHoursZone1And2::input(){

	cin >> *this;

}

void TwoHoursZone1And2::print(){

	cout << this->toString();

}

bool TwoHoursZone1And2::isTravelPass(TravelPass& pUnknown){

	TwoHoursZone1And2* test = dynamic_cast<TwoHoursZone1And2*>(&pUnknown);

	if (test)
		return true;
	else
		return false;

}

string TwoHoursZone1And2::toString(){

	stringstream ss;

	ss << this->length << " pass for " << this->zones << ", costing $" << Utility::floatToString(this->cost, 2) << endl;

	return ss.str();

}

ostream& operator<<(ostream& stream, TwoHoursZone1And2& pass){

	stream << pass.toString();

	return stream;

}

istream& operator>>(istream& stream, TwoHoursZone1And2& pass){

	cout << "Enter length: ";
	stream >> pass.length;

	cout << "Enter zones: ";
	stream >> pass.zones;

	cout << "Enter cost: ";
	stream >> pass.cost;

	return stream;

}
