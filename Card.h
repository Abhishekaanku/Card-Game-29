#ifndef CARD_H
#define CARD_H
#include<vector>
#include<iostream>
using namespace std;
class Card
{
	bool is_face_up=true;
	public:
		static char suit[4];
		static vector<char> num;
		pair<char,char> face;
		Card();
		Card(pair<char,char> face);
		void display();
		void flip();
		unsigned int rank();
		bool operator==(Card C);
		friend ostream &operator<<(ostream &out,Card &C);
		friend istream &operator>>(istream &in,Card &C);
	protected:
};

#endif
