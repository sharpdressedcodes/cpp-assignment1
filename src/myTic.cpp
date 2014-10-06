/*
 * myTic.cpp
 *
 *  Created on: 28/09/2014
 *      Author: greg
 */

#include "myTic.h"

MyTic::MyTic()
: credit(0.0), limit(MAX_LIMIT), maxPasses(0) {
	//
}

MyTic::MyTic(int maxPasses_)
	: credit(0), limit(MAX_LIMIT), maxPasses(maxPasses_){}

MyTic::MyTic(float theCredit, float theLimit, int maxPasses_)
: credit(theCredit), limit(theLimit), maxPasses(maxPasses_){
	//
}

MyTic::~MyTic(){
	//
}

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

void MyTic::buyPass(TravelPass* pass){

	addCredit(-pass->getCost());
	addPurchase(pass);

}

bool MyTic::addPurchase(TravelPass *pUnknown){

	bool result = false;

	if (purchases.size() < maxPasses){
		purchases.push_back(pUnknown);
		result = true;
	}

	return result;

}

void MyTic::clearPurchases(){

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
