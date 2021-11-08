#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h> 
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void draw_ship(int x, int y)
{
	setcolor(15, 0);
	gotoxy(x, y-2); 
	//printf(" <=:o:=> ");
	printf(" o\n");
	gotoxy(x, y-1);
	printf("/|\\!");
	gotoxy(x, y);
	printf(" |");
	gotoxy(x, y+1);
	printf("/ \\");
}

void erase_ship(int x, int y) {
	gotoxy(x, y-2);
	//printf("         ");
	printf("  ");
	gotoxy(x, y - 1);
	printf("    ");
	gotoxy(x, y );
	printf("  ");
	gotoxy(x, y+1);
	printf("   ");
}
void  draw_bullet(int x, int y) {
	setcolor(3, 0);
	gotoxy(x, y);
	printf(" O ");
}

struct Bullet
{
    bool status = false;
    int x = 0, y = 0;
};

void  erase_bullet(int x, int y) {
	gotoxy(x, y);
	setcolor(0, 0);
	printf("   ");
}
int randrange(int start, int stop) {
	return rand() % (stop - start + 1) + start;
}

void score(int Score) {
	gotoxy(75, 1);
	printf("SCORE:%d", Score);
}
void spawnenemy(int x,int y) {
	setcolor(7, 0);
	gotoxy(x, y - 1);
	printf(" -----\n");
	gotoxy(x, y);
	if (x % 2 == 0) printf("| >-< |\n");
	else printf("| O-O |\n");
	gotoxy(x, y + 1);
	printf("\\_____/\n");
}
void eraseenemy(int x, int y) {
	setcolor(7, 0);
	gotoxy(x, y - 1);
	printf("      \n");
	gotoxy(x, y);
	if (x % 2 == 0) printf("       \n");
	else printf("       \n");
	gotoxy(x, y + 1);
	printf("       \n");
}
int main()
{
	char ch = '.';
	int x = 38, y = 20;
	int dir = 0;
	const unsigned int bc = 5;
	Bullet bs[bc];
	setcursor(0);
	draw_ship(x, y);
	for (int i = 0; i < 20; i++) {
		spawnenemy(randrange(10, 70), randrange(2, 60));
	}
	do {
		srand(time(NULL));
		if (_kbhit()) {
			ch = _getch();
			erase_ship(x, y);
			if (ch == 'a') dir = -1;
			if (ch == 'd') dir = 1;
			if (ch == 's') dir = -2;
			if (ch == 'w') dir = 2;
			if (ch == ' ') {	
				dir = 0;
				draw_ship(x, y);
				for (size_t i = 0; i < bc; i++) {				

					if (!bs[i].status) {
						bs[i].status = true;
						bs[i].x = x+4;
						bs[i].y = y-1;
						break;
					}
				}
			}
			if (dir != 0)
			{
				if (dir == -1 && x > 0)
				{
					erase_ship(x, y);
					setcolor(15, 0);
					draw_ship(--x, y);
				}
				if (dir == 1 && x < 80)
				{
					erase_ship(x, y);
					setcolor(15, 0);
					draw_ship(++x, y);
				}
				if (dir == 2 && x < 80)
				{
					erase_ship(x, y);
					setcolor(15, 0);
					draw_ship(x,--y);
				}
				if (dir ==-2 && x < 80)
				{
					erase_ship(x, y);
					setcolor(15, 0);
					draw_ship(x, ++y);
				}
			}
			else {
				draw_ship(x, y);
			}
			fflush(stdin);
		}
		for (size_t i = 0; i < bc; i++) {
			erase_bullet(bs[i].x, bs[i].y);
			if (bs[i].status && bs[i].x <= 80) {
				draw_bullet(++bs[i].x, bs[i].y); 
				if(draw_bullet)
			}
			else {
				bs[i].status = false;
			}
		}
		Sleep(100);

	} while (ch != 'x'&&x<=80);
	return 0;
}