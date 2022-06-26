#include <stdio.h>
int main() {
	int n, a, b, arr[101] = { 0 }, result[10] = { 0 }, count = 0, zero_count = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		for (int j = 0; j < a; j++) {
			scanf("%d", &arr[j]);
			arr[j] += -b;
		}
		for (int j = 0; j < a; j++) {
			if (arr[j] <= 0) {
				zero_count++;
			}
			if (arr[j] > 0 && arr[j + 1] > 0) {
				count++;
			}
		}
		result[i] = a - zero_count - count;
		zero_count = 0;
		count = 0;
		for (int j = 0; j < a; j++)
		{
			arr[j] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", result[i]);
	}

	return 0;
}