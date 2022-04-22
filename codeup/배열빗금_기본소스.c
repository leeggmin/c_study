#include <stdio.h>
int main() {
	int repeat, a, b, arr[101][101] = { 0 }, count = 1;
	scanf("%d %d", &a, &b);
	for (int sum = 0; sum <= a * b; sum++)
	{
		for (int i = 0; i < b; i++)
		{
			for (int j = 0; j < a; j++)
			{
				if (i + j == sum)arr[j][i] = count++;
			}
		}
	}

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}