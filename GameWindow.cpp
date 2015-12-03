#include "stdafx.h"
#include "GameWindow.h"


GameWindow::GameWindow()
{
	//creacion de la ventado
	gameWindow.create(sf::VideoMode(WIDTH, HEIGHT), "TripleTriad");
}
void GameWindow::inicializacion()
{
	gameWindow.setFramerateLimit(60);//la aplicacion corra = velocidad en cualquier maquina
	gameWindow.setKeyRepeatEnabled(false);//evita que el elemento se replique..una vez toco la tecla una sola vez aparece
	gameWindow.setVerticalSyncEnabled(true);//evita q la pantalla parpadee durante la actualizacion
}

void GameWindow::eventos()
{
	// los eventos del pollEvent se contaran 1 vez por el programa luego se reinicia el event
	while (gameWindow.pollEvent(evento))
	{
		if (evento.type == sf::Event::Closed)
			gameWindow.close();
	}

}
void GameWindow::update() // Moviemientos, fisica, etc...
{
	musicLibrary.getMusic();
}
void GameWindow::render() // Declara un render a la ventana por frame
{
	gameWindow.clear(sf::Color::White);
	//actions
	gameWindow.display();
}
void GameWindow::run()
{
	inicializacion();
	while (gameWindow.isOpen())
	{
		eventos();
		update();
		render();
	}
}
GameWindow::~GameWindow()
{
}
