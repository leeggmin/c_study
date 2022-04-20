#include <stdio.h>
int land_mine[11][11]={0}, x, y, result = 0,
	repeat = 3, sign = 1;
int main() {
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			scanf("%d", &land_mine[i][j]);
		}
	}
	scanf("%d %d", &x, &y);
	if (land_mine[x][y] == 1) {
		printf("-1");
		return 0;
	}
	x -= 1;
	y -= 2;
	while (1)
	{
		for (int i = 1; i <=repeat ; i++)
		{
			y += sign;
			if (land_mine[x][y] == 1) {
				//printf("%d %d\n", x, y);
				result++;
			}
		}
		repeat--;
		if (repeat == 0) {
			if (result == 0) {
				printf("0");
				break;
			}
			printf("%d", result);
			break;
		}
		for (int i = 1; i <= repeat; i++)
		{
			x += sign;
			if (land_mine[x][y] == 1) {
				//printf("%d %d\n", x,y);
				result++;
			}
		}
		sign *= -1;
	}

	return 0;
}