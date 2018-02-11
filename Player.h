#ifndef PLAYER_H
#define PLAYER_H

#include "hand.h"
#include "Card.h"
class Player : public Hand
{
	public:
		char name[10];
		int point;
		Player();
		Player(char *name);
		void display();
		bool throw_card(Card C);
	protected:
};

#endif
