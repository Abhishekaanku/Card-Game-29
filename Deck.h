#ifndef DECK_H
#define DECK_H

#include "hand.h"
#include "Auto.h"

class Deck : public Hand
{
	public:
		void fill();
		void cut(int x);
		void deal(Player &H1,Auto &h2,int per_hand);
	protected:
};

#endif
