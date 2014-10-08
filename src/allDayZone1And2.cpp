#include "allDayZone1And2.h"

const float AllDayZone1And2::DEFAULT_PRICE = 6.8;
const string AllDayZone1And2::DEFAULT_LENGTH = "All Day";
const string AllDayZone1And2::DEFAULT_ZONES = "Zones 1 and 2";

AllDayZone1And2::AllDayZone1And2()
	: TravelPass(DEFAULT_LENGTH, DEFAULT_ZONES, DEFAULT_PRICE) {}

AllDayZone1And2::~AllDayZone1And2(){}

void AllDayZone1And2::input(){}

void AllDayZone1And2::print(){

	cout << this->toString();

}

bool AllDayZone1And2::isTravelPass(TravelPass& pUnknown){

	AllDayZone1And2* test = dynamic_cast<AllDayZone1And2*>(&pUnknown);

	if (test)
		return true;
	else
		return false;

}

string AllDayZone1And2::toString(){

	stringstream ss;

	ss << this->length << " pass for " << this->zones << ", costing $" << Utility::floatToString(this->cost, 2) << endl;

	return ss.str();

}

ostream& operator<<(ostream& stream, AllDayZone1And2& pass){

	stream << pass.toString();

	return stream;

}

istream& operator>>(istream& stream, AllDayZone1And2& pass){

	cout << "Enter length: ";
	stream >> pass.length;

	cout << "Enter zones: ";
	stream >> pass.zones;

	cout << "Enter cost: ";
	stream >> pass.cost;

	return stream;

}
