#include <stdio.h>
int main()
{
	int h, w, n; //h=����, w=����, n=������ ����, i=������ ����, d=����, ��ǥ(x,y) 
	int aa[100][100] = { 0,0 }; //2���� �迭
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
	//���δ� d=0, ���δ� d=1

	for (int nnn = 0; nnn < n; nnn++) //������ ������ŭ
	{
		if (d[nnn] == 0) //���� 
		{
			for (int count = 0; count < i[nnn]; count++)//������ ���̸�ŭ
			{
				if (count != 0)
				{
					aa[x[nnn]-1][y[nnn]+ count-1] = 1;
				}
				aa[x[nnn]-1][y[nnn]-1] = 1;
				
			}
		}
		else //����
		{
			for (int count2 = 0; count2 < i[nnn]; count2++) //������ ���̸�ŭ
			{
				if (count2 != 0)
				{
					aa[x[nnn]+ count2-1][y[nnn]-1] = 1;
				}
				aa[x[nnn]-1][y[nnn]-1] = 1;
			}
		}
	}

	//���
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