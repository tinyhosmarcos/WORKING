#include "stdafx.h"
#include "CardStorage.h"

Card CardStorage::V001("Ifrit", 8, 2, 9, 6, 1);
Card CardStorage::V002("Shiva", 8, 2, 9, 6, 1);
Card CardStorage::V003("Bahamut", 5, 8, 2, 5, 1);
Card CardStorage::V004("quetzalcoatl", 2, 2, 9, 6, 1);
Card CardStorage::V005("Berus", 4, 4, 5, 5, 1);
Card CardStorage::V006("Belias", 1, 6, 6, 6, 1);
Card CardStorage::V007("Chaos", 3, 7, 9, 2, 1);
Card CardStorage::V008("Zalera", 7, 2, 6, 3, 1);
Card CardStorage::V009("Zeromus", 5, 5, 2, 3, 1);
Card CardStorage::V010("Hashmal", 4, 5, 1, 1, 1);
Card CardStorage::V011("Exodus", 1, 2, 5, 6, 1);
Card CardStorage::V012("Cuchulainn", 6, 2, 7, 2, 1);
Card CardStorage::V013("Shemhazai", 3, 7, 2, 8, 1);
Card CardStorage::V014("Adrammelech", 8, 2, 9, 6, 1);
Card CardStorage::V015("Famfrit", 6, 9, 2, 3, 1);
Card CardStorage::V016("Mateus", 3, 2, 5, 2, 1);
Card CardStorage::V017("Zodiark", 2, 2, 4, 8, 1);
Card CardStorage::V018("Ultima", 2, 5, 7, 6, 1);
Card CardStorage::V019("DoomTrain", 6, 7, 2, 6, 1);
Card CardStorage::V020("Carbuncle", 7, 2, 4, 4, 1);

Card CardStorage::Storage[20] = { V001, V002, V003, V004, V005, V006, V007, V008, V009, V010, V011, V012, V013, V014, V015, V016, V017, V018, V019, V020 };

CardStorage::CardStorage()
{
}

Card CardStorage::getCard(int i){
	return Storage[i];
}

CardStorage::~CardStorage()
{
}
