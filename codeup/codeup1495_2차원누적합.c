#include <stdio.h>
int d[1001][1001] = {0}, array[1001][1001] = {0};
int main(){
	int x1,x2,y1,y2,n,k,sum=0,m;
	scanf("%d %d %d", &n,&m,&k);
	//�Է�
	for (int i = 0; i < k; i++)
	{
		scanf("%d %d %d %d %d",&array[i][0], &array[i][1], &array[i][2], &array[i][3], &array[i][4]);
	}
	//���ڵ�
	for (int i = 0; i < k; i++)
	{
		d[array[i][0]][array[i][1]] += array[i][4];
		d[array[i][2]+1][array[i][3]+1] += array[i][4];
		d[array[i][0]][array[i][3]+1] -= array[i][4];
		d[array[i][2]+1][array[i][1]] -= array[i][4];
	}
	//���
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
	//2���� ������ �ڵ� �����ϱ�!!
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
	//���
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