#ifndef _PADDLE_H
#define _PADDLE_H
#include "Header.h"
class Paddle
{
protected:
	COORD pos;
	short width;
public:
	Paddle();
	Paddle(short, short, short);

	inline void setX(short x) { pos.X = x; };
	inline void setY(short y) { pos.Y = y; };
	inline void setW(short w) { width = w; };
	void gotoXY(HANDLE, COORD);
	

};

#endif 


