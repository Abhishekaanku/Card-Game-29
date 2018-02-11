#include "Card.h"
#include<algorithm>
using namespace std;
char no[]={'K','Q','J','A','9','8','7','6','5'};
vector<char> Card::num(no,no+sizeof(no)/sizeof(char));
char Card::suit[]={'S','H','C','D'};
Card::Card() {
	face.first='\0';
}
Card::Card(pair<char,char> face) {
	this->face.first=face.first;
	this->face.second=face.second;
}
void Card::display() {
	cout<<*this;
}
void Card::flip() {
	is_face_up=!is_face_up;
}
unsigned int Card::rank() {
	vector<char>::iterator I=find(num.begin(),num.end(),face.second);
	return(int(9-(I-num.begin())));
}
bool Card::operator==(Card C) {
	if(face.first==C.face.first && face.second==C.face.second) {
		return(true);
	}
	return(false);
}
ostream &operator<<(ostream &out,Card &C) {
	if(C.is_face_up) {
		out<<C.face.first<<C.face.second<<" ";
	}
	else {
		out<<"XX"<<" ";
	}
	return(out);
}
istream &operator>>(istream &in,Card &C) {
	char temp;
	do {
		in.get(temp);
	}
	while(temp=='\n');
	C.face.first=temp;
	in.get(C.face.second);
	return(in);
}
