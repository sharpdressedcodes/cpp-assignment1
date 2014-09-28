/*
 * myTic.cpp
 *
 *  Created on: 28/09/2014
 *      Author: greg
 */

#include "myTic.h"

MyTic::MyTic()
: credit(0.0), limit(MAX_LIMIT){
	//
}

MyTic::MyTic(float theCredit, float theLimit)
: credit(theCredit), limit(theLimit){
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
