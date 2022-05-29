#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define BACK 4
#define SUBMIT 5

int main_Menu_x = 3, main_Menu_y = 1, end_sign = 0, before_y=1;
int player_x, player_y, game_result=0, level=3;
int select_x = 2, select_y = 3;
int arr[20][20] = { 0 }, count;
void init();
void gameRule();
void gameStart(int);
int keyControl();
void mind(int, int);
void gotoxy(int, int);
void mainMenu(int);
void clear();
void arrClear();
int levelSelect();

int main() {
	
	init();
	while (1) {
		if (end_sign != 0) {
			return 0;
		}
		mainMenu(before_y);
	}
}

void mainMenu(int y) {
	
	gotoxy(0, 0);
	printf("┌――――――――┐\n");
	printf("│    게임시작    │\n");
	printf("│    게임설명    │\n");
	printf("│   난이도 선택  │\n");
	printf("│      종료      │\n");
	printf("└――――――――┘");
	gotoxy(3, y);
	if (y == 3) gotoxy(2, y);
	printf(">");
	gotoxy(main_Menu_x, main_Menu_y);

	while (1) {
		int menu_key = keyControl();
		switch (menu_key)
		{
			case UP: {
				if (main_Menu_y > 1) {
					if (main_Menu_y == 3) {
						gotoxy(main_Menu_x - 1, main_Menu_y);
						printf(" ");
					}
					gotoxy(main_Menu_x, main_Menu_y);
					printf(" ");
					main_Menu_y--;
					if (main_Menu_y == 3) {
						gotoxy(main_Menu_x-1, main_Menu_y);
						printf(">");
						break;
					}
					gotoxy(main_Menu_x, main_Menu_y);
					printf(">");
				}
				break;
			}
			case DOWN: {
				if (main_Menu_y < 4) {
					if (main_Menu_y == 3) {
						gotoxy(main_Menu_x - 1, main_Menu_y);
						printf(" ");
					}
					gotoxy(main_Menu_x, main_Menu_y);
					printf(" ");
					main_Menu_y++;
					if (main_Menu_y == 3) {
						gotoxy(main_Menu_x - 1, main_Menu_y);
						printf(">");
						break;
					}
					gotoxy(main_Menu_x, main_Menu_y);
					printf(">");
				}
				break;
			}
			case SUBMIT: {
				if (main_Menu_y == 1) {
					clear();
					gameStart(level);
					before_y = 1;
				}
				else if (main_Menu_y == 2) {
					gameRule();
					before_y = 2;
				}
				else if (main_Menu_y == 3) {
					clear();
					level = levelSelect();
					before_y = 3;
				}
				else {
					gotoxy(0,6);
					end_sign = 1;
				}
				return 0;
			}
		}
	}
	
}

void init() {

	system("mode con cols=50 lines=20 | title 두더지 잡기");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void mind(int cnt1, int cnt2) {

	cnt2 += 1;
	srand(time(NULL));
	int random_x,random_y;
	for (int i = 0; i < cnt1; i++)
	{
		random_x = rand() % cnt2;
		random_y = rand() % cnt2;
		if (arr[random_x][random_y] == 1 || (random_x==cnt1&&random_y==cnt1)) {
			i--;
			continue;
		}
		arr[random_x][random_y] = 1;
	}
}

int keyControl() {

	char temp = getch();
	
	if (temp == 'w' || temp == 'W') {
		return UP;
	}
	else if (temp == 'a' || temp == 'A') {
		return LEFT;
	}
	else if (temp == 's' || temp == 'S') {
		return DOWN;
	}
	else if (temp == 'd' || temp == 'D') {
		return RIGHT;
	}
	else if (temp == 'q' || temp == 'Q') {
		return BACK;
	}
	else if (temp == ' ') {
		return SUBMIT;
	}
}

void gotoxy(int x,int y) {

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void gameStart(int level) {
	int cnt1, cnt2;
	if (level == 2) {//하
		cnt1 = 3;
		cnt2 = 4;
	}
	else if (level == 3) {//중
		cnt1 = 5;
		cnt2 = 10;
	}
	else {//상
		cnt1 = 7;
		cnt2 = 14;
	}
	player_x = cnt2/2;
	player_y = cnt2/2;
	count = cnt1;

	mind(cnt1, cnt2);
	clock_t start, now;
	start = clock();
	while (1) {

		for (int i = 0; i <= cnt2; i++)
		{
			for (int j = 0; j <= cnt2; j++)
			{
				gotoxy(i, j);
				printf("%d", arr[i][j]);
			}
		}

		gotoxy(player_x, player_y);
		printf("2");

		if (count == 0 && (double)(now - start) / 1000 < 10) {
			gotoxy(cnt2+2, cnt2/2-1);
			printf("성공!!");
			gotoxy(cnt2 + 2, cnt2/2);
			printf("걸린 시간 : %.2lfs", (double)(now - start) / 1000);
			game_result = 1;
			gotoxy(cnt2 + 2, cnt2/2+1);
			printf("메인화면으로 가려면 Q를 누르세요.");
		}

		int game_key = keyControl();
		if(game_result!=1) now = clock();

		if ((double)(now - start)/1000 >= 10 && game_result==0) {
			gotoxy(cnt2 + 2, cnt2 / 2);
			printf("시간초과 실패!!");
			gotoxy(cnt2 + 2, cnt2 / 2+1);
			printf("메인화면으로 가려면 Q를 누르세요.");
		}

		switch (game_key)
		{
			case UP: {
				if (player_y <= 0)continue;
				player_y += -1;
				break;
			}
			case DOWN: {
				if (player_y >= cnt2)continue;
				player_y += 1;
				break;
			}
			case LEFT: {
				if (player_x <= 0)continue;
				player_x += -1;
				break;
			}
			case RIGHT: {
				if (player_x >= cnt2)continue;
				player_x += 1;
				break;
			}
			case BACK: {
				clear();
				arrClear();
				game_result = 0;
				return 0;
			}
			case SUBMIT: {
				if (arr[player_x][player_y] == 1) {
					arr[player_x][player_y] = 0;
					count--;
				}
				break;
			}
		}
	}
}

void gameRule() {
	gotoxy(0, 0);
	printf("┌――――――――――┐\n");
	printf("│    - 조작방법 -    │\n");
	printf("│ 이동 : W, A, S, D  │\n");
	printf("│ 잡기 : 스페이스바  │\n");
	printf("│ 메인으로 :   Q     │\n");
	printf("├――――――――――┤\n");
	printf("│   - 인게임설명 -   │\n");
	printf("│                    │\n");
	printf("│ 제한시간 내에 모든 │\n");
	printf("│두더지를 잡으면 성공│\n");
	printf("│                    │\n");
	printf("│      빈곳 : 0      │\n");
	printf("│     두더지 : 1     │\n");
	printf("│    플레이어 : 2    │\n");
	printf("├――――――――――┤\n");
	printf("│   개발자 :  1102   │\n");
	printf("│            이지민  │\n");
	printf("└――――――――――┘");
	while (1) {
		int rule_key = keyControl();
		switch (rule_key)
		{
			case BACK: {
				clear();
				return 0;
			}
		}
	}
}

int levelSelect() {
	gotoxy(0, 0);
	printf("┌――――――――――┐\n");
	printf("│  - 난이도 선택 -   │\n");
	printf("│   하 : 5*5, 3개    │\n");
	printf("│   중 : 10*10, 5개  │\n");
	printf("│   상 : 15*15, 7개  │\n");
	printf("│                    │\n");
	printf("│ 결정 : 스페이스바  │\n");
	printf("└――――――――――┘");
	gotoxy(select_x, select_y);
	printf(">");
	while (1) {
		int rule_key = keyControl();
		switch (rule_key)
		{
			case UP: {
				if (select_y > 2) {
					gotoxy(select_x, select_y);
					printf(" ");
					select_y--;
					gotoxy(select_x, select_y);
					printf(">");
				}
				break;
			}
			case DOWN: {
				if (select_y < 4) {
					gotoxy(select_x, select_y);
					printf(" ");
					select_y++;
					gotoxy(select_x, select_y);
					printf(">");
				}
				break;
			}
			case SUBMIT: {
				clear();
				return select_y;
			}
		}
	}
}

void clear() {
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			gotoxy(i, j);
			printf(" ");
		}
	}
}

void arrClear() {
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			arr[i][j] = 0;
		}
	}
}