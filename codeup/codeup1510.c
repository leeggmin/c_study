#include <stdio.h>
int main() {
	int n,arr[50][50],count=1;
	scanf("%d", &n);
	int x = 0, y = n / 2;
	for (int i = 0; i < n*n; i++)
	{
		if (x < 0)x = n - 1;
		if (y >= n)y = 0;
		arr[x][y] = count;
		if (count % n == 0) {
			count++;
			x++;
			continue;
		}
		count++;
		x--;
		y++;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}