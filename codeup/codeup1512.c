#include <stdio.h>
int main() {
	int n,str[200][200]={0}, x, y, sign = 1, temp,sign2=1;
	scanf("%d", &n);
	scanf("%d %d", &x, &y);
	str[x][y] = 1;
	int bk_x = x,bk_y=y, repeat = n - x,repeat2=n-y+1;
	if (n % 2 == 0)repeat++;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 1; j <= repeat2; j++)
		{
			temp = str[x][y];
			y += sign;
			str[x][y] = temp + 1;
		}
		sign *= -1;
		y = bk_y;
		repeat2 = n - repeat2;
	}
	repeat2 = n - y + 1;
	for (int k = 1; k <= 2; k++)
	{
		for (int l = 1; l <= repeat2; l++)
		{
			for (int i = 1; i <= 2; i++)
			{
				for (int j = 1; j <= repeat; j++)
				{
					temp = str[x][y];
					x += sign;
					str[x][y] = temp + 1;
				}
				sign *= -1;
				x = bk_x;
				repeat = n - repeat;
			}
			y += sign2;
		}
		sign2 *= -1;
		y = bk_y - 1;
		repeat2 = n-repeat2;
	}

	//Ãâ·Â
	for (int i = 1; i <=n ; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%d ", str[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}