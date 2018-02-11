#include <iostream>
#include "Game_29.h"
#include<vector>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Game_29 game;
	game.start_game();
	game.declare_result();
	cout<<"Press any key to exit"<<endl;
	getch();
	return 0;
}
