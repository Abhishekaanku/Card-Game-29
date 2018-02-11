#include "Player.h"
#include "Card.h"
#include<string.h>
#include<algorithm>
using namespace std;
Player::Player() {}
Player::Player(char *name) {
	strcpy(this->name,name);
	point=0;
}
void Player::display() {
	cout<<name<< " ";
	if(cards.empty()) {
		cout<<"EMPTY"<<" ";
		cout<<"("<<point<<")"<<endl;
		return;
	}
	vector<Card>::iterator I;
	for(I=cards.begin();I!=cards.end();++I) {
		cout<<*I;
	}
	cout<<"("<<point<<")"<<endl;
}
bool Player::throw_card(Card C) {
	vector <Card>::iterator I;
	I=find(cards.begin(),cards.end(),C);
	if(I==cards.end()) {
		return false;
	}
	cards.erase(I);
	return true;
}
