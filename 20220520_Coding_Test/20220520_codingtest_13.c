#include <stdio.h>
int main() {
	int b, a, result2[10] = { 0 }, count = 0, count2 = 0,
		result[11] = { 0,100,200,300,400,500,600,700,800,900 };
	while (1) {
		scanf("%d", &a);
		if (a == 0) {
			break;
		}
		result2[a / 100] += 1;
		count++;
		if (a >= 300)count2++;
	}
	if (count % 2 == 0)count = count / 2;
	if (count % 2 == 1)count = count / 2 + 1;
	for (int i = 0; i < 10; i++) {
		if (result2[i] != 0) {
			printf("%d : %d개\n", result[i], result2[i]);
		}
	}
	if (count2 >= count)printf("목표 달성!");

	return 0;
}