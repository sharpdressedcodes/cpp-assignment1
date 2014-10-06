#include "twoHoursZone1.h"

const float TwoHoursZone1::DEFAULT_PRICE = 2.5;
const string TwoHoursZone1::DEFAULT_LENGTH = "2 Hours";
const string TwoHoursZone1::DEFAULT_ZONES = "Zone 1";

TwoHoursZone1::TwoHoursZone1()
	: TravelPass(DEFAULT_LENGTH, DEFAULT_ZONES, DEFAULT_PRICE) {}

TwoHoursZone1::~TwoHoursZone1(){}

void TwoHoursZone1::input(){}

void TwoHoursZone1::print(){

	cout << this->length << " pass for " << this->zones << ", costing $" << Utility::floatToString(this->cost, 2) << endl;

}
