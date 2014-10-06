#include "allDayZone1.h"

const float AllDayZone1::DEFAULT_PRICE = 4.9;
const string AllDayZone1::DEFAULT_LENGTH = "All Day";
const string AllDayZone1::DEFAULT_ZONES = "Zone 1";

AllDayZone1::AllDayZone1()
	: TravelPass(DEFAULT_LENGTH, DEFAULT_ZONES, DEFAULT_PRICE) {}

AllDayZone1::~AllDayZone1(){}

void AllDayZone1::input(){}

void AllDayZone1::print(){}
