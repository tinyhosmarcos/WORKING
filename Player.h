#pragma once
#include <string>
#include <ctime>
#include <cstdlib>
#include "CardStorage.h"
#include "Card.h"

using namespace std;
class Player  // : public CardStorage
{
private:
	static string status;
	string name;
	string faction;
	Card deck[5];
	CardStorage cardStorage;
	

public:
	Player();
	Player(string name, string faction);
	string getName();
	Card getDeck(int i);
	void RandomDeck();
	void playerTurn();
	~Player();
};

