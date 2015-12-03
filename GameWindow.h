#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "MusicLibrary.h"
#include <memory>

static const unsigned int WIDTH = 1024;
static const unsigned int HEIGHT = 768;

class GameWindow
{
private	:
	sf::RenderWindow gameWindow;
	sf::Event evento;
	MusicLibrary musicLibrary;
public:
	GameWindow();
	void eventos();
	void inicializacion();
	void update();
	void render();
	void run();	
	~GameWindow();
};

