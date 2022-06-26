#include <stdio.h>
struct student {
	char name[20];
	double hei;
};

int main() {

	int n;
	double heiavg = 0; //평균 키
	struct student member[10] = { '\0',0 };
	scanf("%d", &n); //학생 수 입력받기
	for (int i = 0; i < n; i++)
	{
		scanf("%s %lf", member[i].name, &member[i].hei);
		heiavg += member[i].hei;
	}
	heiavg /= (double)n;

	for (int i = 0; i < n; i++) {
		printf("%s ", member[i].name);
		if (member[i].hei > heiavg)
			printf("UP\n");
		else if (member[i].hei == heiavg)
			printf("SAME\n");
		else
			printf("DOWN\n");
	}

	return 0;
}