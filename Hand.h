#ifndef HAND_H
#define HAND_H
#include "Card.h"
using namespace std;

class Hand
{
	public:
		vector <Card> cards;
		void shuffle();
		void erase();
		void give(Hand &H);
	protected:
};

#endif
