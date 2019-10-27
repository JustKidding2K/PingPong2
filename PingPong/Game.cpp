#include "Game.h"

Game::Game() {
	width = 60;
	heigh = 30;
	ball.setX(width / 2);
	ball.setY(heigh / 2);

	score1 = 0;
	score2 = 0;
}
bool Game:: checkInRange(COORD& posBall,short& band,COORD& posPlayer) {
	if (posBall.X < posPlayer.X)return 0;
	if (posBall.X > posPlayer.X + band - 1)return 0;
	return 1;
}
Game::Game(short w, short h,short band) {
	width = w;
	heigh = h;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ball.setX(w / 2);
	ball.setY(h / 2);

	COORD posBall;
	posBall.X = ball.getX();
	posBall.Y = ball.getY();
	ball.gotoXY(hConsole,posBall);
	ball.setDir(UP);
	

	score1 = 0;
	score2 = 0;
	COORD build = { 0,0 };
	
	for (short i = 0; i < heigh; i++) {
		build.X = 0;
		build.Y = i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), build);
		WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), "#", 1, NULL, NULL);
		build.X = width;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), build);
		WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), "#", 1, NULL, NULL);
	}

	COORD posPlayer1 = { width / 2 - band / 2, heigh - 1 };
	COORD posPlayer2 = { width / 2 - band / 2, 0 };

	player1.setX(width / 2);
	player1.setY(1);
	player1.setW(10);

	player2.setX(width / 2);
	player1.setY(heigh - 1);
	player2.setW(10);

	player1.gotoXY(hConsole, posPlayer1);
	player2.gotoXY(hConsole, posPlayer2);

	
	
	
	//Hide cursor- https://www.gamedev.net/forums/topic/201413-hiding-text-cursor-in-c-console-applications/
	CONSOLE_CURSOR_INFO f;
	f.dwSize = 100;
	f.bVisible = 0;
	SetConsoleCursorInfo(hConsole, &f);
	//End Hide Cursor
	int KB_code = 0;
	//https://www.reddit.com/r/learnprogramming/comments/1dlxqv/c_measuring_time_elapsed_in_milliseconds/
	auto begin = high_resolution_clock::now();
	auto end = high_resolution_clock::now();
	auto dur = end - begin;
	auto ms = duration_cast<milliseconds>(dur).count();
	float speed=0.5;

	while (KB_code != KB_ESCAPE)
	{

		if (_kbhit())
		{
			KB_code = _getch();
			//printf("KB_code = %i \n", KB_code);

			switch (KB_code)
			{
				//Player 1
			case KB_LEFT:
				//Move Left
				if (posPlayer1.X > 1 ) {

					posPlayer1.X--;

					player1.gotoXY(hConsole, posPlayer1);
				}
				break;

			case KB_RIGHT:
				//Move right
				if (posPlayer1.X < width - band) {
					posPlayer1.X++;

					player1.gotoXY(hConsole, posPlayer1);
				}
				break;

			case KB_UP:
				//Move up
				if (posPlayer1.Y > 0 ) {
					if (posPlayer1.Y == posBall.Y + 1)
						if (checkInRange(posBall, band, posPlayer1))
							break;

					posPlayer1.Y--;
					player1.gotoXY(hConsole, posPlayer1);
				}
				break;

			case KB_DOWN:
				//Move down 
				if (posPlayer1.Y < heigh - 1) {
					
					if (posPlayer2.Y == posBall.Y - 1)
						if (checkInRange(posBall, band, posPlayer2))
							break;

					posPlayer1.Y++;
					player1.gotoXY(hConsole, posPlayer1);
				}
				break;
			//Player 2
			case 'a':
				//Move Left
				if (posPlayer2.X > 1) {
					posPlayer2.X--;
					player2.gotoXY(hConsole, posPlayer2);
				}
				break;

			case 'd':
				//Move right
				if (posPlayer2.X < width - band) {
					posPlayer2.X++;
					player2.gotoXY(hConsole, posPlayer2);
				}
				break;
			case 'w':
				//Move up
				if (posPlayer2.Y > 0) {
					posPlayer2.Y--;
					player2.gotoXY(hConsole, posPlayer2);
					
				}
				break;
			case 's':
				//Move down 
				if (posPlayer2.Y < heigh - 1 &&posPlayer2.Y <posBall.Y-1) {
					posPlayer2.Y++;
					player2.gotoXY(hConsole, posPlayer2);
				}
				break;

			}

		}
		//Ball move
		end = high_resolution_clock::now();
		dur = end - begin;
		ms = duration_cast<milliseconds>(dur).count();
		
		if ( ms>1000*speed) {
			switch (ball.getDir())
			{
//==============================================================
			case UP:
				if (posBall.Y >=1) {// && posBall.Y>posPlayer2.Y+1
					
					if(posBall.Y==posPlayer2.Y+1)
					if (checkInRange(posBall,band,posPlayer2)) {
						srand(time(NULL));
						speed = speed * 0.9;
						ball.setDir(rand() % 6 + 1);
						//ball.setDir(DOWN);
						break;
					}
					else {
						//Defeat
					}
					posBall.Y--;
					ball.gotoXY(hConsole, posBall);
				}
				
				break;
//==============================================================
			case DOWN:
				if (posBall.Y <= heigh-2) {

					if(posBall.Y==posPlayer1.Y-1)
					if (checkInRange(posBall,band,posPlayer1)) {
						srand(time(NULL));
						speed = speed * 0.9;
						ball.setDir(rand()%6+1);
						//ball.setDir(UP);
						break;
					}
					else {
						//Defeat

					}

					posBall.Y++;
					ball.gotoXY(hConsole, posBall);
				}
				
				break;
//==============================================================
			case UPLEFT:
				if (posBall.Y > 1 && posBall.X > 1) {
					
					posBall.X--;
					posBall.Y--;
					ball.gotoXY(hConsole, posBall);
				}
				else if (posBall.X == 1 && posBall.Y == 1 && checkInRange(posBall, band, posPlayer2)) {
					speed = speed * 0.9;
					ball.setDir(DOWNRIGHT);
				}
				else if (posBall.X == 1)
					ball.setDir(UPRIGHT);

				else if (checkInRange(posBall, band, posPlayer2)) {
					ball.setDir(DOWNLEFT);
					speed = speed * 0.9;
				}
				else if (posBall.X == posPlayer2.X + 1 && posBall.Y == posPlayer2.Y + 1) {
					ball.setDir(DOWNRIGHT);
					//speeed
				}
				else {
					posBall.X--;
					posBall.Y--;
					ball.gotoXY(hConsole, posBall);
					Sleep(1000 * speed);
					cout << "Player2 defeated";

				}
				
			break;
//==============================================================
			case UPRIGHT:
				if (posBall.Y > 1 && posBall.X < width-2) {
					
					posBall.X++;
					posBall.Y--;
					ball.gotoXY(hConsole, posBall);
				}
				else if (posBall.X == width - 2 && posBall.Y == 1 && checkInRange(posBall, band, posPlayer2)) {
					ball.setDir(DOWNLEFT);
					speed = speed * 0.9;
				}
				else if (posBall.X == width - 2)
					ball.setDir(UPLEFT);

				else if (checkInRange(posBall, band, posPlayer2)) {
					ball.setDir(DOWNRIGHT);
					speed = speed * 0.9;
				}
				else if (posBall.X == posPlayer2.X - 1 && posBall.Y == posPlayer2.Y + 1) {
					ball.setDir(DOWNLEFT);
					//speeed
				}
				else {
					posBall.X++;
					posBall.Y--;
					ball.gotoXY(hConsole, posBall);
					Sleep(1000 * speed);
					cout << "Player2 defeated";
				}
				
				break;
//==============================================================
			case DOWNLEFT:
				if (posBall.Y < heigh-2 && posBall.X > 1) {
					
					posBall.X--;
					posBall.Y++;
					ball.gotoXY(hConsole, posBall);
				}
				else if (posBall.X == 1 && posBall.Y == heigh - 2 && checkInRange(posBall, band, posPlayer1)) {
					ball.setDir(UPRIGHT);
					speed = speed * 0.9;
				}
				else if (posBall.X == 1)
					ball.setDir(DOWNRIGHT);

				else if (checkInRange(posBall, band, posPlayer1)) {
					ball.setDir(UPLEFT);
					speed = speed * 0.9;
				}
				else {
					posBall.X--;
					posBall.Y++;
					ball.gotoXY(hConsole, posBall);
					Sleep(1000 * speed);
					cout << "Player1 defeated";
				}
				
				break;
//==============================================================
			case DOWNRIGHT:
				if (posBall.Y < heigh - 2 && posBall.X < width-2) {
					
					posBall.X++;
					posBall.Y++;
					ball.gotoXY(hConsole, posBall);
				}
				else if (posBall.X == width - 2 && posBall.Y == heigh - 2 && checkInRange(posBall, band, posPlayer1)) {
					ball.setDir(UPLEFT);
					speed = speed * 0.9;
				}
				else if (posBall.X == width - 2)
					ball.setDir(DOWNLEFT);

				else if (checkInRange(posBall, band, posPlayer1)) {
					ball.setDir(UPRIGHT);
					speed = speed * 0.9;
				}
				else {
					posBall.X++;
					posBall.Y++;
					ball.gotoXY(hConsole, posBall);
					Sleep(1000 * speed);
					cout << "Player1 defeated";
				}
				
				break;
			default:
				break;
			};
			begin = high_resolution_clock::now();
		}
	}
	
}
