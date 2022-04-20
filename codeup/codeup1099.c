#include <stdio.h>
int main()
{
	int aa[10][10] = { 0,0 }; //2���� �迭
	int ant[20][20] = { 0,0 }; //���� �̵� ��� 

	//�Է�
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			scanf("%d", &aa[i][j]);
		}
	}

	int a = 1;
	int b = 1;

	while (1)
	{
		if (aa[a][b] == 0)
		{
			aa[a][b] = 9;
			b++;
		}
		else if (aa[a][b] == 1)
		{
			a++;
			b -= 1;
		}
		else
		{
			aa[a][b] = 9;
			break;
		}
		
	}

	//���
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%d ", aa[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}