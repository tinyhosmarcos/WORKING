#pragma once

#include "Player.h"
#include "Card.h"
#include "CardStorage.h"
#include <string>
#include <ctime>

class GameBoard 
{
private:
	Player ptrPlayer01;
	Player ptrPlayer02;
	static Card a1, a2, a3, b1, b2, b3, c1, c2, c3;
	static Card arrCards[];
	Card **tripleTriadBoard;	
	 	
public:	
	GameBoard();
	Player getPlayer(int playerNumber);
	void setPtrPlayer(Player player, int playerNumber);
	void placeCard(Card card, int posX, int posY);//x=fil,y=col
	void flippingFactions(int posX, int posY);
	void playerTurn(Player player);
	void printBoard();

	

	~GameBoard();
};

