#include <stdio.h>
int main() {

	int arr[10][10],user[10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &user[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		if (user[i] == 1) {
			for (int j = 9; j >= 0; j--)
			{
				if (arr[j][i] != 0) {
					if (arr[j][i] > 0) {
						printf("%d crash\n", i + 1);
						break;
					}
					else if(arr[j][i]<0) {
						printf("%d fall\n", i + 1);
						break;
					}
				}
				if (j == 0)printf("%d safe\n", i + 1);
			}
		}
	}
	return 0;
}