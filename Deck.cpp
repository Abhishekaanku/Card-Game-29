#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include "Auto.h"
void Deck::fill() {
	for(int i=0;i<4;++i) {
		vector<char>::iterator I;
		for(I=Card::num.begin();I!=Card::num.end();++I) {
			cards.push_back(Card(make_pair(Card::suit[i],*I)));
		}
	}
} 
void Deck::cut(int x) {
	vector<Card> temp;
	vector<Card>::iterator I=cards.begin();
	advance(I,x);
	temp.insert(temp.end(),I,cards.end());
	vector<Card>::iterator crawl;
	for(crawl=cards.begin();crawl!=I;++crawl) {
		temp.push_back(*crawl);
	}
	cards.assign(temp.begin(),temp.end());
}
void Deck::deal(Player &H1,Auto &H2,int per_hand) {
	int count=0;
	while(count<per_hand) {
		give(H1);
		give(H2);
		++count;
	}
}

