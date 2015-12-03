#include "stdafx.h"
#include "MusicLibrary.h"

MusicLibrary::MusicLibrary()
{
	music_gameplay_BoS = &music;
	if (!music.openFromFile("BoS.ogg"))
		printf("error");
	
	
}

sf::Music &MusicLibrary::getMusic()
{
	return music;
}

MusicLibrary::~MusicLibrary()
{
	
}
