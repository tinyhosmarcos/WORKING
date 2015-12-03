#include "stdafx.h"
#include "Card.h"

using namespace std;
Card::Card()
{
	name = "unidentified";
	topValue = 0;
	bottomValue = 0;
	rightValue = 0;
	leftValue = 0;
	faction = "primaria";	
}

Card::Card(string name, int topValue, int bottomValue, int rightValue, int leftValue, int player)
{
	this->name = name;
	this->topValue = topValue;
	this->bottomValue = bottomValue;
	this->rightValue = rightValue;
	this->leftValue = leftValue;

	if (player == 1)
		faction = "red";
	if (player == 2)
		faction = "blue";
}

void Card::setCardNumber(int topValue, int bottomValue, int rightValue, int leftValue)
{
	this->topValue = topValue;
	this->bottomValue = bottomValue;
	this->rightValue = rightValue;
	this->leftValue = leftValue;
}

void Card::getCardValues()
{
	printf("Card: %s      Faction: %s\n\n", name.c_str(), faction.c_str());//.c_str es para que salga el nombre
	printf("topValue: %d \nbottomValue: %d \nrightValue: %d \nleftValue: %d\n\n\n\n", topValue, bottomValue, rightValue, leftValue);
}

int Card::getTopValue(){
	return topValue;
}

int Card::getBottomValue(){
	return bottomValue;
}

int Card::getRightValue(){
	return rightValue;
}

int Card::getLeftValue(){
	return leftValue;
}

string Card::getName(){
	return name;
}

string Card::getFaction(){
	return faction;
}

void Card::setFaction(string faction)
{
	this->faction = faction;
}

Card::~Card()
{}
