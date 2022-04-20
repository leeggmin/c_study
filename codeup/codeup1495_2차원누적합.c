#include <stdio.h>
int d[1001][1001] = {0}, array[1001][1001] = {0};
int main(){
	int x1,x2,y1,y2,n,k,sum=0,m;
	scanf("%d %d %d", &n,&m,&k);
	//입력
	for (int i = 0; i < k; i++)
	{
		scanf("%d %d %d %d %d",&array[i][0], &array[i][1], &array[i][2], &array[i][3], &array[i][4]);
	}
	//본코드
	for (int i = 0; i < k; i++)
	{
		d[array[i][0]][array[i][1]] += array[i][4];
		d[array[i][2]+1][array[i][3]+1] += array[i][4];
		d[array[i][0]][array[i][3]+1] -= array[i][4];
		d[array[i][2]+1][array[i][1]] -= array[i][4];
	}
	//출력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
	//2차원 누적합 코드 이해하기!!
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum += d[i][j];
			d[i][j] = sum;
		}
		sum = 0;
	}
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			sum += d[i][j];
			d[i][j] = sum;
		}
		sum = 0;
	}
	//출력
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
    return 0;
}