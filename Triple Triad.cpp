// Triple Triad.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "Card.h"
#include "CardStorage.h"
#include "GameBoard.h"
#include "Player.h"
#include "GameWindow.h"
#include "MusicLibrary.h"
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned)time(NULL)); // inicializar semilla dentro de clase?

	//iniciamos el archivo de musica
	sf::RenderWindow window(sf::VideoMode(800, 600), "Triple Triad");
	sf::Music music_BoS;
	if (!music_BoS.openFromFile("BoS.ogg"))
		return -1; // error
	music_BoS.play();
	music_BoS.setLoop(true);
	GameBoard board;
	
	//creamos los jugador
	Player player01("Peter", "red");
	Player player02("Cibergato2045", "blue");
	board.setPtrPlayer(player01, 1);
	board.setPtrPlayer(player02, 2);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			window.close();
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		window.clear();
		window.display();
	}
	while (1)
	{
		printf("\n\n------------------------O------------------------\n\n");
		board.playerTurn(board.getPlayer(1));
		board.printBoard();
		printf("\n\n------------------------O------------------------\n\n");
		board.playerTurn(board.getPlayer(2));
		board.printBoard();
	}
	//GameWindow game;
	//game.run();

	
	_getch();
	return 0;
}
