#include <stdio.h>
int testcase[101][101] = { 0 }, test_result[101]={0},
real_result[101] = {0};
int main() {
	int n,temp;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <=3; j++)
		{
			scanf("%d", &testcase[i][j]);
		}
		scanf("%d", &test_result[i]);
	}

	for (int k = 1; k <= n; k++)
	{
		//¹öºísort
		for (int i = 1; i <= 2; i++)
		{
			for (int j = 1; j <= 2; j++)
			{
				if (testcase[k][j] > testcase[k][j + 1])
				{
					temp = testcase[k][j];
					testcase[k][j] = testcase[k][j + 1];
					testcase[k][j + 1] = temp;
				}
			}
		}
		real_result[k] = testcase[k][1];
	}

	for (int i = 1; i <= n; i++)
	{
		if (real_result[i] != test_result[i]) {
			printf("%d %d", i, real_result[i]);
			return 0;
		}
	}
	printf("-1");

	return 0;
}
