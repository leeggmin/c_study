#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double gameCount = 0, success = 0;
void mainGame();
void goalkeeper(int result);
int keepGame();
double shoot_success();

main()
{
	printf("[ 골 넣기 게임 ]\n\n");
	while (1) {
		mainGame();
		int replay = keepGame();
		if (replay == 1)continue;
		else {
			printf("Shoot 성공률 : %.2lf%%", shoot_success());
			return 0;
		}
	}
}

void mainGame() {
	srand(time(NULL));
	int a, random = 0;
	random = rand() % 2;
	gameCount+=1;
	printf("%.0lf번째 시도\n", gameCount);
	printf("┌――――――――――――-―――┐\n");
	printf("│               ●              │\n");
	printf("│  왼쪽 : 0   ┎ ╋ ┑  오른쪽 : 1 │\n");
	printf("│               ┃               │\n");
	printf("│               /＼             │\n");
	printf(">> ");
	scanf("%d", &a);
	if (a != 0 && a != 1) {
		printf("올바른 값을 입력해주세요.\n");
		return 0;
	}
	else if (random == a) {
		printf("No Goal  ");
	}
	else {
		printf("Goal!!  ");
		success+=1;
	}
	goalkeeper(random);
}

void goalkeeper(int result) {
	if (result == 0) {
		printf("(골키퍼는 왼쪽을 막았습니다.)\n");
	}
	else {
		printf("(골키퍼는 오른쪽을 막았습니다.)\n");
	}
}

int keepGame() {
	int play;
	printf("Continue? (Yes : 1 or No : 0) >> ");
	scanf("%d", &play);
	if (play == 1)printf("\n");
	return play;
}

double shoot_success() {
	return success / gameCount * 100;
}