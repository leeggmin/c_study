#include <stdio.h>
int main() {
	int a, b, dog_leg, chick_leg;
	scanf("%d %d", &a, &b);
	for (int i = 0; i <= a; i++) {
		dog_leg = i * 4;
		for (int j = 0; j <= a; j++)
		{
			chick_leg = j * 2;
			if (dog_leg + chick_leg == b && i + j == a) {
				printf("���Ƹ� %d����, ������ %d����", j, i);
				return 0;
			}
		}
	}
	printf("0");

	return 0;
}