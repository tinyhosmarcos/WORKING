#include "stdafx.h"
#include "GameBoard.h"
#include <iostream>
#include <stdio.h>

using namespace std;

Card GameBoard::a1;
Card GameBoard::a2;
Card GameBoard::a3;
Card GameBoard::b1;
Card GameBoard::b2;
Card GameBoard::b3;
Card GameBoard::c1;
Card GameBoard::c2;
Card GameBoard::c3;
Card GameBoard::arrCards[9] = { a1, a2, a3, b1, b2, b3, c1, c2, c3 };

GameBoard::GameBoard()
{ 
	//declarando
	tripleTriadBoard = new Card*[3];

	for (int i = 0; i < 3; i++){
		tripleTriadBoard[i] = new Card[3];
	}	
	// inicializando tablero con las posiciones neutras(arrCards)
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tripleTriadBoard[i][j] = arrCards[3*i+j];
		}
		cout << endl;
	}
	
}

Player GameBoard::getPlayer(int playerNumber){
	if (playerNumber > 0 && playerNumber <=2)
	{
		if (playerNumber == 1)
			return ptrPlayer01;
		if (playerNumber == 2)
			return ptrPlayer02;
	}	
	return ptrPlayer01;
	
	
}

void GameBoard::setPtrPlayer(Player Player, int playerNumber){
	if (playerNumber > 0 && playerNumber <= 2)
	{
		if (playerNumber == 1)
			ptrPlayer01 = Player;
		if (playerNumber == 2)
			ptrPlayer02 = Player;
	}
}

void GameBoard::placeCard(Card card, int posX, int posY)
{
	if (tripleTriadBoard[posX][posY].getFaction() == "primaria")// para que solo pueda reemplazar las cartas primarias y no de jugadores
		tripleTriadBoard[posX][posY] = card;
	flippingFactions(posX, posY);
}

void GameBoard::flippingFactions(int posX, int posY)
{
	
	if ((posX - 1 >= 0 && posX - 1 < 3) && tripleTriadBoard[posX - 1][posY].getFaction() != "primaria")//top
	{
		if (tripleTriadBoard[posX][posY].getFaction() != tripleTriadBoard[posX - 1][posY].getFaction())
		{
			if (tripleTriadBoard[posX][posY].getTopValue() > tripleTriadBoard[posX - 1][posY].getBottomValue())
			{
				if (tripleTriadBoard[posX][posY].getFaction() == "red")
					tripleTriadBoard[posX - 1][posY].setFaction("red");
				if (tripleTriadBoard[posX][posY].getFaction() == "blue")
					tripleTriadBoard[posX - 1][posY].setFaction("blue");
			}
		}
	}

	if ((posX + 1 >= 0 && posX + 1 < 3) && tripleTriadBoard[posX + 1][posY].getFaction() != "primaria")//bot
	{
		if (tripleTriadBoard[posX][posY].getFaction() != tripleTriadBoard[posX + 1][posY].getFaction())
		{
			if (tripleTriadBoard[posX][posY].getBottomValue() > tripleTriadBoard[posX + 1][posY].getTopValue())
			{
				if (tripleTriadBoard[posX][posY].getFaction() == "red")
					tripleTriadBoard[posX + 1][posY].setFaction("red");
				if (tripleTriadBoard[posX][posY].getFaction() == "blue")
					tripleTriadBoard[posX + 1][posY].setFaction("blue");
			}
		}
	}

	if ((posY + 1 >= 0 && posY + 1 < 3) && tripleTriadBoard[posX][posY + 1].getFaction() != "primaria")//right
	{
		if (tripleTriadBoard[posX][posY].getFaction() != tripleTriadBoard[posX][posY + 1].getFaction())
		{
			if (tripleTriadBoard[posX][posY].getRightValue() > tripleTriadBoard[posX][posY + 1].getLeftValue())
			{
				if (tripleTriadBoard[posX][posY].getFaction() == "red")
					tripleTriadBoard[posX][posY + 1].setFaction("red");
				if (tripleTriadBoard[posX][posY].getFaction() == "blue")
					tripleTriadBoard[posX][posY + 1].setFaction("blue");
			}
		}
	}

	if ((posY - 1 >= 0 && posY - 1 < 3) && tripleTriadBoard[posX][posY - 1].getFaction() != "primaria")//left
	{
		if (tripleTriadBoard[posX][posY].getFaction() != tripleTriadBoard[posX][posY - 1].getFaction())
		{
			if (tripleTriadBoard[posX][posY].getLeftValue() > tripleTriadBoard[posX][posY - 1].getRightValue())
			{
				if (tripleTriadBoard[posX][posY].getFaction() == "red")
					tripleTriadBoard[posX][posY - 1].setFaction("red");
				if (tripleTriadBoard[posX][posY].getFaction() == "blue")
					tripleTriadBoard[posX][posY - 1].setFaction("blue");
			}
		}
	}
	

}

void GameBoard::playerTurn(Player player)
{
	int option = 1;
	string card;
	Card card2Choose;
	printf("%s's turn : write the name of the card to place\n", player.getName().c_str());
	while (1)
	{
		int x = 0, y =0;
		printf("\n[1]View Cards in deck  [2]place Card : ");
		scanf_s("%d", &option);
		while (option != 1 && option != 2)
		{
			printf("\nInvalid!");
			printf("\n[1]View Cards in deck  [2]place Card : ");
			scanf_s("%d", &option);
		}
		printf("\n\n");
		switch (option)
		{
		case 1:		
			player.getDeck(0).getCardValues();
			player.getDeck(1).getCardValues();
			player.getDeck(2).getCardValues();
			player.getDeck(3).getCardValues();
			player.getDeck(4).getCardValues();
			break;	

		case 2:
			printf("introduce el nombre de la carta: ");
			cin >> card;
			for (int i = 0; i < 5; i++)
			{
				if (player.getDeck(i).getName().c_str() == card)
					card2Choose = player.getDeck(i);				
			}
			printf("\nintroduce la ubicacion [Fila] :");
			scanf_s("%d", &x);
			printf("\nintroduce la ubicacion [Columna] :");
			scanf_s("%d", &y);
			placeCard(card2Choose,x,y);
			break;
		}
		if (option == 2)
			break;
	}
}

void GameBoard::printBoard(){
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (tripleTriadBoard[i][j].getFaction() == "primaria")
				printf(" X ");
			if (tripleTriadBoard[i][j].getFaction() == "red")
				printf(" R ");
			if (tripleTriadBoard[i][j].getFaction() == "blue")
				printf(" B ");
		}
		cout << endl;
	}
}

GameBoard::~GameBoard()
{
}
