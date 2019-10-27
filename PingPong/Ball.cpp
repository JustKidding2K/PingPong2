#include "Ball.h"
Ball::Ball() {
	//startPos.X = 0;
	//startPos.Y = 0;
	
	Pos.X = 0;//startPos.X;
	Pos.Y = 0;//startPos.Y;

	Direction = STOP;

}
Ball::Ball(short posX, short posY) {
	//startPos.X = posX;
	//startPos.Y = posY;
	
	Pos.X = posX; //startPos.X;
	Pos.Y = posY;//startPos.Y;

	Direction = STOP;
}
void Ball::reset() {
	Pos.X = 0;
	Pos.Y = 0;
	//startPos.X = 0;
	//startPos.Y = 0;
	Direction = STOP;
}
void Ball :: gotoXY(HANDLE hConsole, COORD desPos) {
	SetConsoleCursorPosition(hConsole, Pos);
	WriteConsole(hConsole," ",1,NULL, NULL);
	
	SetConsoleCursorPosition(hConsole, desPos);
	WriteConsole(hConsole, "O", 1, NULL, NULL);
	Pos = desPos;


}

void Ball::move(int d) {
	switch (d)
	{
	case STOP: {
		Direction = 0;
		break; 
	}
	case UP: {
		break;
	}
	case UPRIGHT: {
		break;
	}

	case DOWNRIGHT: {
		break;
	}
	case DOWN: {
		break;
	}
	case DOWNLEFT: {
		break;
	}

	
	case UPLEFT: {

		break;
	}

	}

}

