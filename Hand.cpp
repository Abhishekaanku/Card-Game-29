#include "Hand.h"
#include "Card.h"
#include<time.h>
#include<stdlib.h>
void swap(Card &, Card &);
void Hand::shuffle() {
	srand(time(NULL));
	for(int i=cards.size()-1;i>0;--i) {
		int index=rand()%i;
		swap(cards[i],cards[index]);
	}
}
void Hand::erase() {
	cards.clear();
}
void Hand::give(Hand &H) {
	if(cards.size()) {
		H.cards.push_back(*cards.begin());
		cards.erase(cards.begin());
	}
}
void swap(Card &C1,Card &C2) {
	Card temp=C1;
	C1=C2;
	C2=temp;
}
