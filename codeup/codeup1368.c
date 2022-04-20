#include <stdio.h>
int main() {
	int h, k;
	char d;
	scanf("%d %d %c", &h,&k,&d);
	int check = h - 1;
	if (d == 'L') {
		for (int i = 1; i <= h; i++)
		{
			for (int a = 0; a < i-1; a++)
			{
				printf(" ");
			}
			for (int b = 0; b < k; b++)
			{
				printf("*");
			}
			for (int c = check; c >0; c--)
			{
				printf(" ");
			}
			check--;
			printf("\n");
		}
	}
	else {
		for (int i = 1; i <= h; i++)
		{
			for (int c = check; c > 0; c--)
			{
				printf(" ");
			}
			for (int b = 0; b < k; b++)
			{
				printf("*");
			}
			for (int a = 0; a < i - 1; a++)
			{
				printf(" ");
			}
			check--;
			printf("\n");
		}
	}

	return 0;
}
