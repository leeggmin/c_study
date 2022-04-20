#include <stdio.h>
int main()
{
	int h, w, n; //h=세로, w=가로, n=막대의 개수, i=막대의 길이, d=방향, 좌표(x,y) 
	int aa[100][100] = { 0,0 }; //2차원 배열
	int i[10] = { 0 }; 
	int d[10] = { 0 };
	int x[10] = { 0 };
	int y[10] = { 0 };
	scanf("%d %d", &h, &w);
	scanf("%d", &n);
	for (int nn = 0; nn < n; nn++)
	{
		scanf("%d %d %d %d", &i[nn], &d[nn], &x[nn], &y[nn]);
	}
	//가로는 d=0, 세로는 d=1

	for (int nnn = 0; nnn < n; nnn++) //막대의 개수만큼
	{
		if (d[nnn] == 0) //가로 
		{
			for (int count = 0; count < i[nnn]; count++)//막대의 길이만큼
			{
				if (count != 0)
				{
					aa[x[nnn]-1][y[nnn]+ count-1] = 1;
				}
				aa[x[nnn]-1][y[nnn]-1] = 1;
				
			}
		}
		else //세로
		{
			for (int count2 = 0; count2 < i[nnn]; count2++) //막대의 길이만큼
			{
				if (count2 != 0)
				{
					aa[x[nnn]+ count2-1][y[nnn]-1] = 1;
				}
				aa[x[nnn]-1][y[nnn]-1] = 1;
			}
		}
	}

	//출력
	for (int v = 0; v < h; v++)
	{
		for (int j = 0; j < w; j++)
		{
			printf("%d ", aa[v][j]);
		}
		printf("\n");
	}

	return 0;
}