#include "twoHoursZone1And2.h"

const float TwoHoursZone1And2::DEFAULT_PRICE = 3.5;
const string TwoHoursZone1And2::DEFAULT_LENGTH = "2 Hours";
const string TwoHoursZone1And2::DEFAULT_ZONES = "Zones 1 and 2";

TwoHoursZone1And2::TwoHoursZone1And2()
	: TravelPass(DEFAULT_LENGTH, DEFAULT_ZONES, DEFAULT_PRICE) {}

TwoHoursZone1And2::~TwoHoursZone1And2(){}

void TwoHoursZone1And2::input(){}

void TwoHoursZone1And2::print(){

	cout << this->length << " pass for " << this->zones << ", costing $" << Utility::floatToString(this->cost, 2) << endl;

}
