#ifndef COMPUTER_H
#define COMPUTER_H
#include "Player.h"
class Auto:public Player
{
	public:
		Auto();
		Card select_auto(Card C,char col);
		Card select_auto(char col);
		char select_color();
	protected:
};

#endif
