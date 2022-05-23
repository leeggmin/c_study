#include <stdio.h>
int main() {
	int a, b[1001], c[1001], temp, count = 0;
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf("%d", &b[i]);
		temp = b[i];
		while (temp != 0) {
			if (temp % 2 == 0) {
				temp = temp / 2;
			}
			else {
				count++;
				temp = temp / 2;
			}
		}
		c[i] = count;
		count = 0;
	}
	int min = c[0];
	for (int i = 1; i < a; i++) {
		if (c[i] == min) {
			if (b[i] < b[temp]) {
				temp = i;
				min = c[i];
			}
			else continue;
		}
		if (c[i] > min) {
			temp = i;
			min = c[i];
		}
	}
	printf("%d", b[temp]);

	return 0;
}