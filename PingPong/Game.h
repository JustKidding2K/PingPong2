#ifndef _GAME_H
#define _GAME_H

#include "Header.h"
#include "Ball.h"
#include "Paddle.h" 

#define KB_UP 72
#define KB_DOWN 80
#define KB_LEFT 75
#define KB_RIGHT 77
#define KB_ESCAPE 27

class Game
{


protected:
	Ball ball;
	Paddle player1;
	Paddle player2;
	short width, heigh;
	int score1, score2;

public:
	Game();
	Game(short, short,short);
	bool checkInRange(COORD& posBall, short& band, COORD& posPlayerw);

};



#endif 
