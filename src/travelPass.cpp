#include "travelPass.h"

TravelPass::TravelPass()
	: cost(0) {}

TravelPass::TravelPass(string theLength, string theZones, float theCost)
	: length(theLength), zones(theZones), cost(theCost){}

TravelPass::~TravelPass(){}

string TravelPass::getLength() const {
	return length;
}

string TravelPass::getZones() const {
	return zones;
}

float TravelPass::getCost() const {
	return cost;
}

void TravelPass::setLength(string newLength){
	length = newLength;
}

void TravelPass::setZones(string newZones){
	zones = newZones;
}

void TravelPass::setCost(float newCost){
	cost = newCost;
}
