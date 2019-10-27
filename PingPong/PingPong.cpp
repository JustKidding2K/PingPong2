
#include"Header.h"
#include "Ball.h"
#include "Paddle.h"
#include "Game.h"
#define KB_UP 72
#define KB_DOWN 80
#define KB_LEFT 75
#define KB_RIGHT 77
#define KB_ESCAPE 27

int main()
{
	SetConsoleOutputCP(65001);
	int width = 40;
	int heigh = 15;
	int band = 10;
	Game game1(width, heigh, band);
	/*COORD pos = { width / 2 - band / 2, heigh - 1 };
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	Paddle d(width/2, heigh,10);
	d.gotoXY(hConsole,pos);
	
	
	Game game1(40,15);

	//Hide cursor- https://www.gamedev.net/forums/topic/201413-hiding-text-cursor-in-c-console-applications/
	CONSOLE_CURSOR_INFO f;
	f.dwSize = 100;
	f.bVisible = 0;
	SetConsoleCursorInfo(hConsole, &f);
	//End Hide Cursor
	int KB_code = 0;

	while (KB_code != KB_ESCAPE)
	{
		if (_kbhit())
		{
			KB_code = _getch();
			//printf("KB_code = %i \n", KB_code);

			switch (KB_code)
			{
			case KB_LEFT:
				//Move Left
				if (pos.X > 0)
					pos.X--;
				else continue;
				d.gotoXY(hConsole,pos);
				break;

			case KB_RIGHT:
				//Move right
				pos.X++;
				d.gotoXY(hConsole, pos);
				break;

			case KB_UP:
				//Move up
				if (pos.Y > 0)
					pos.Y--;
				else continue;
				d.gotoXY(hConsole, pos);
				break;

			case KB_DOWN:
				//Move down 
				pos.Y++;
				d.gotoXY(hConsole, pos);
				break;

			}

		}
	}
	*/
}
