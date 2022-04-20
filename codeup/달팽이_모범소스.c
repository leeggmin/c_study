#include <stdio.h>
int main() {
	int count,num=1,array[101][101],
		x=0,y=-1,sign=1;
	scanf("%d", &count);
	int repeat = count;
	while (1) {
		for (int i = 0; i < repeat; i++)
		{
			y += sign;
			array[x][y] = num;
			num++;
		}

		repeat--;
		if (repeat == 0) break;

		for (int i = 0; i < repeat; i++)
		{
			x += sign;
			array[x][y] = num;
			num++;
		}
		sign *= -1;
	}

	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
	return 0;
}
