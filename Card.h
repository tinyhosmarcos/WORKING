#pragma once
#include <iostream>
#include <string>
using namespace std;

class Card 
{
private:
	string name;
	int topValue, bottomValue, rightValue, leftValue;
	string faction;
	
public:
	Card();
	Card(string name, int topValue, int bottomValue, int rightValue, int leftValue, int player);
	void setCardNumber(int topValue, int bottomValue, int rightValue, int leftValue);
	void getCardValues();
	int getTopValue();
	int getBottomValue();
	int getRightValue();
	int getLeftValue();
	string getName();
	string getFaction();
	void setFaction(string faction);
	
	~Card();
};

