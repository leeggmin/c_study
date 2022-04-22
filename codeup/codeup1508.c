#include <stdio.h>
int arr[101][101];
int main() {
	int a, sum = 0 ,last_print = 1;
	scanf("%d", &a);
	int b = 1,temp1,temp2;
	
	for (int i = 0; i < a; i++)
	{
		scanf("%d", &arr[i][0]);
	}
	
	for (int i = 1; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			temp1 = arr[i - 1][j];
			temp2 = arr[i][j];
			arr[i][j + 1] = temp2 - temp1;
		}
		b++;
	}
	
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < last_print; j++)
		{
			printf("%d ", arr[i][j]);
		}
		last_print++;
		printf("\n");
	}
	return 0;
}