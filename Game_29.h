#ifndef GAME_29_H
#define GAME_29_H
#include "Player.h"
#include "Auto.h"

class Game_29
{
	public:
		Player P;
		Auto A;
		int turn;
		char col;
		Game_29();
		void start_game();
		void display_score();
		void display_score(Card prev,Card cur,int turn);
		bool check_condition(Card prev, Card cur);
		void declare_result();
	protected:
};

#endif
