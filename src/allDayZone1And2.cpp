#include "allDayZone1And2.h"

const float AllDayZone1And2::DEFAULT_PRICE = 6.8;
const string AllDayZone1And2::DEFAULT_LENGTH = "All Day";
const string AllDayZone1And2::DEFAULT_ZONES = "Zones 1 and 2";

AllDayZone1And2::AllDayZone1And2()
	: TravelPass(DEFAULT_LENGTH, DEFAULT_ZONES, DEFAULT_PRICE) {}

AllDayZone1And2::~AllDayZone1And2(){}

void AllDayZone1And2::input(){}

void AllDayZone1And2::print(){

	cout << this->length << " pass for " << this->zones << ", costing $" << Utility::floatToString(this->cost, 2) << endl;

}
