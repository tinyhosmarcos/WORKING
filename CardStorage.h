#pragma once
#include "Card.h"
#include <string>
class CardStorage 
{
private:
	static Card V001;
	static Card V002;
	static Card V003;
	static Card V004;
	static Card V005;
	static Card V006;
	static Card V007;
	static Card V008;
	static Card V009;
	static Card V010;
	static Card V011;
	static Card V012;
	static Card V013;
	static Card V014;
	static Card V015;
	static Card V016;
	static Card V017;
	static Card V018;
	static Card V019;
	static Card V020;

	static Card Storage[20];
public:
	CardStorage();
	Card getCard(int i);
	~CardStorage();
};

