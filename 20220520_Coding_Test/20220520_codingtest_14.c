#include <stdio.h>
int main() {
	int n, temp, arr[11] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		for (int j = 0; j < n; j++) {
			if (temp == 0 && arr[j] == 0) {
				arr[j] = i + 1;
				break;
			}
			else if (arr[j] == 0)temp--;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}