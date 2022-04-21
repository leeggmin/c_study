#include<stdio.h>
int main() {

	int n,arr1[2001]={0},arr2[2001]={0},temp;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr1[i]);
		arr2[i] = arr1[i];
	}

	//bubble sort
	for (int i = 1; i <= n-1; i++)
	{
		for (int j = 1; j <= n-1; j++)
		{
			if (arr2[j] < arr2[j + 1])
			{
				temp = arr2[j];
				arr2[j] = arr2[j + 1];
				arr2[j + 1] = temp;
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		temp = arr1[i];
		for (int j = 1; j <=n; j++)
		{
			if (temp == arr2[j]) {
				printf("%d\n", j);
				break;
			}
		}
	}

	return 0;
}