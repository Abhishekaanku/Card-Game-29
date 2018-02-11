#include "Auto.h"
#include "Card.h"
#include<stdlib.h>
Auto::Auto():Player("Computer") {
}
Card Auto::select_auto(char col) {
	vector<Card>::iterator I;
	Card temp1,temp2;
	int max1=1,max2=1;
	for(I=cards.begin();I!=cards.end();++I) {
		if(I->face.first==col) {
			if(I->rank()>max2) {
				temp2=*I;
				max2=I->rank();
			}
		}
		else {
			if(I->rank()>max1) {
				temp1=*I;
				max1=I->rank();
			}
		}
	}
	if(temp1.face.first=='\0') {
		return(temp2);
	}
	return(temp1);
}
Card Auto::select_auto(Card C,char col) {
	int rank=C.rank();
	char face=C.face.first;
	vector<Card>::iterator I;
	Card temp_card1;
	Card temp_card2;
	Card temp_card3;
	Card temp_card4;
	int min1=10,min2=10,min3=10,min4=10;
	for(I=cards.begin();I!=cards.end();++I) {
		int temp_rank=I->rank();
		if(I->face.first==face) {
			if(temp_rank>rank && temp_rank<min1) {
				temp_card1=*I;
				min1=temp_rank;
			}
			else if(temp_rank<rank && temp_rank<min2){
				temp_card2=*I;
				min2=temp_rank;
			}
		}
		else if(I->face.first==col) {
			if(temp_rank<min3)  {
				temp_card3=*I;
				min3=temp_rank;
			}
		}
		else {
			if(temp_rank<min4) {
				temp_card4=*I;
				min4=temp_rank;
			}
		}
	}
	if(temp_card1.face.first!='\0') {
		return(temp_card1);
	}
	else if(temp_card2.face.first!='\0') {
		return(temp_card2);
	}
	else if(temp_card3.face.first!='\0') {
		return(temp_card3);
	}
	else {
		return(temp_card4);
	}
}
char Auto::select_color() {
	vector<Card>::iterator I;
	int *cnt=(int *)calloc(4,sizeof(int));
	for(I=cards.begin();I!=cards.end();++I) {
		for(int i=0;i<4;++i) {
			if(Card::suit[i]==I->face.first) {
				cnt[i]+=1;
			}
			if(cnt[i]>1) {
				return(Card::suit[i]);
			}
		}
	}
}
