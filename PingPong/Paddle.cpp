#include "Paddle.h"

Paddle:: Paddle() {
	pos.X = 0;
	pos.Y = 0;
	width = 1;
}

Paddle::Paddle(short x, short y, short w) {
	pos.X = x;
	pos.Y = y;
	width = w;

}

void Paddle::gotoXY(HANDLE hConsole,COORD desPos) {
	
	SetConsoleCursorPosition(hConsole, pos);

	for (int i = 0; i < width; i++)
	WriteConsole(hConsole, " ", 1, NULL, NULL);

	SetConsoleCursorPosition(hConsole, desPos);
	for (int i = 0; i < width; i++)
	WriteConsole(hConsole, "#", 1, NULL, NULL);
	pos = desPos;

}

