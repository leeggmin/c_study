#include <stdio.h>
int main()
{
	int arr[10][10] = { 0 },sum=0,x=1,y=1,result=0;
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	for (int l = 1; l <= 3; l++)
	{
		for (int k = 1; k <= 3; k++)
		{
			for (int i = 1; i <= 3; i++)
			{
				for (int j = 1; j <= 3; j++)
				{
					sum += arr[x][y];
					y++;
				}
				x++;
				y -= 3;
			}
			if (sum > result) {
				result = sum;
			}
			sum = 0;
			if (k == 3) {
				x -= 2;
				y -= 2;
				continue;
			}
			x -= 3;
			y++;
		}
	}
	
	printf("%d", result);

	return 0;
}