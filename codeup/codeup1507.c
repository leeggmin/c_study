#include <stdio.h>
int main() {

	int arr[101][101] = { 0 }, arr2[4][5] = { 0 },result=0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			scanf("%d", &arr2[i][j]);
		}
		arr2[i][2] -= 1;
		arr2[i][3] -= 1;
	}

	for (int k = 0; k < 4; k++)
	{
		for (int i = arr2[k][0]; i <= arr2[k][2]; i++)
		{
			for (int j = arr2[k][1]; j <= arr2[k][3]; j++)
			{
				arr[i][j] = 1;
			}
		}
	}

	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= 100; j++)
		{
			result += arr[i][j];
		}
	}
	printf("%d", result);

	return 0;
}