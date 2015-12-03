#pragma once
#include <SFML/Audio.hpp>
using namespace std;
class MusicLibrary
{
private:	
	sf::Music *music_gameplay_BoS;
	sf::Music music;

public:
	MusicLibrary();
	sf::Music &getMusic();
	~MusicLibrary();
};

