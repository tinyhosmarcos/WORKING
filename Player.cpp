#include "stdafx.h"
#include "Player.h"
#include <ctime>

string Player::status = "Random";

Player::Player()
{
	name = "unidentified";
	faction = "primaria";
	RandomDeck();
}

Player::Player(string name, string faction)
{
	this->name = name;
	this->faction = faction;
	RandomDeck();
}

string Player::getName(){
	return name;
}

Card Player::getDeck(int i){
	return deck[i];
}

void Player::RandomDeck()
{

	for (int i = 0; i < 5; i++)
	{

		int r = rand()%20;
		deck[i] = cardStorage.getCard(r);
		deck[i].setFaction(faction);//convertimos a faction del jugador
	}
}

Player::~Player(){
}
