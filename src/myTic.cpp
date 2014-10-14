/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment #1 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "myTic.h"

float MyTic::MAX_LIMIT = 100;
unsigned int MyTic::AMOUNT_DIVISOR = 5;

MyTic::MyTic()
: credit(0.0), limit(MAX_LIMIT), maxPasses(0) {}

MyTic::MyTic(int maxPasses_)
	: credit(0), limit(MAX_LIMIT), maxPasses(maxPasses_){}

MyTic::MyTic(float theCredit, float theLimit, int maxPasses_)
: credit(theCredit), limit(theLimit), maxPasses(maxPasses_){}

MyTic::~MyTic(){}

float MyTic::getCredit() const {
	return credit;
}

float MyTic::getLimit() const {
	return limit;
}

unsigned int MyTic::getMaxPasses() const {
	return maxPasses;
}

void MyTic::setMaxPasses(unsigned int newValue){
	maxPasses = newValue;
}

void MyTic::input(){
	//
}

void MyTic::print(){
	//
}

bool MyTic::addCredit(float amount){

	if (credit + amount > limit)
		return false;

	credit += amount;
	return true;

}

bool MyTic::buyPass(TravelPass* pass){

	if (purchases.size() >= maxPasses)
		return false;

	addCredit(-pass->getCost());
	purchases.push_back(pass);

	return true;

}

void MyTic::clearPurchases(){

	for (size_t i = 0; i < purchases.size(); i++)
		delete purchases[i];

	purchases.clear();

}

unsigned int MyTic::getPurchaseCount() const {
	return purchases.size();
}

vector<TravelPass*> MyTic::getPurchases() const {
	return purchases;
}

float MyTic::getPurchaseTotal() const {

	float result = 0;

	for (vector<TravelPass*>::const_iterator it = purchases.begin(); it != purchases.end(); ++it)
		result += (*it)->getCost();

	return result;

}
