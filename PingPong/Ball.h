#ifndef _BALL_H
#define _BALL_H
#include "Header.h"

const int STOP=0;
const int UP=1;
const int	UPRIGHT =2;
const int	DOWNRIGHT =3;
const int	DOWN = 4;
const int	DOWNLEFT= 5;
const int	UPLEFT = 6;



class Ball
{
protected:
	COORD Pos;
	//COORD startPos;
	int Direction;
public:
	Ball();
	Ball(short, short);
	//~Ball();
	inline short getX() { return Pos.X; };
	inline short getY() { return Pos.Y; };
	
	inline void setX(short posX) { Pos.X = posX; };
	inline void setY(short posY) { Pos.Y = posY; };

	inline void setDir(int d) { Direction = d; }
	inline int getDir() { return Direction; }

	void gotoXY(HANDLE,COORD);
	void move(int d);
	void reset();
};

#endif 



