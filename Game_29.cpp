#include "Game_29.h"
#include "Card.h"
#include "Deck.h"
using namespace std;
Game_29::Game_29() {
	cout<<"Enter your name: ";
	char name[10];
	cin>>name;
	P=Player(name);
	Deck deck;
	deck.fill();
	deck.shuffle();
	int cut;
	cout<<"Enter the no. for the card to cut(1-18): ";
	cin>>cut;
	deck.cut(cut);
	deck.deal(P,A,5);
	cout<<"Do you want to throw first? ";
	char cond;
	cin>>cond;
	if(cond=='Y') {
		P.display();
		cout<<"Select color: ";
		cin>>col;
		turn=1;
	}
	else {
		col=A.select_color();
		turn=0;
	}
	deck.deal(P,A,13);
	vector<Card>::iterator I;
	for(I=A.cards.begin();I!=A.cards.end();++I) 
		I->flip();
}
void Game_29::display_score() {
	system("cls");
	P.display();
	A.display();
}
void Game_29::display_score(Card prev,Card cur,int tur) {
	display_score();
	if(tur==1) {
		cout<<"Computer's Move: "<<prev<<endl; 
		cout<<"Your Move: "<<cur<<endl;
	}
	else {
		cout<<"Your Move: "<<prev<<endl;
		cout<<"Computer's Move: "<<cur<<endl;
	}
}
bool Game_29::check_condition(Card prev, Card cur) {
	return((cur.rank()>prev.rank() && cur.face.first==prev.face.first) || (prev.face.first!=col && cur.face.first==col));
}
void Game_29::start_game() {
	Card prev,cur;
	display_score();
	cout<<"Color for the game is "<<col<<endl;
	while(!P.cards.empty() || !A.cards.empty()) {
		puts("");
		if(turn==1) {
			cout<<"Enter your next move(Suit<space>Number): ";
			cin>>cur;
			if(!P.throw_card(cur)) {
				cout<<"Card not in your deck!"<<endl;
				continue;
			}
			if(prev.face.first!='\0') {
				if(check_condition(prev,cur)) {
					++P.point;
				}
				else {
					++A.point;
					turn=0;
				}
				display_score(prev,cur,1);
				prev=Card(make_pair('\0','\0'));
			}
			else {
				prev=cur;
				turn=0;
			}
		}
		else {
			if(prev.face.first!='\0') {
				cur=A.select_auto(prev,col);
				cur.flip();
				A.throw_card(cur);
				if(check_condition(prev,cur)) {
					++A.point;
				}
				else {
					++P.point;
					turn=1;
				}
				display_score(prev,cur,0);
				prev=Card(make_pair('\0','\0'));
			}
			else {
				prev=A.select_auto(col);
				prev.flip();
				cout<<"Computer's next Move::"<<prev<<endl;
				A.throw_card(prev);
				turn=1;
			}
		}
	}
}
void Game_29::declare_result() {
	if(P.point>A.point) {
		cout<<"Congratulation! You won the game !\nThanks for playing"<<endl;
	}
	else if(P.point<A.point) {
		cout<<"Wow, AI won the game....\n Try better next time"<<endl;
	}
	else {
		cout<<"Good Try !! Game tied! You have almost done it..Try better next time and thanx for playing"<<endl;
	}
}
