#include<stdio.h>
int main() {
	int a,b,c,arr1[1001] = { 0 },
		arr2[1001] = { 0 }, arr3[1001] = { 0 },
		count1=1,count2=1,count3=1,result,temp;
	scanf("%d %d %d", &a,&b,&c);
	for (int i = 1; i <= a; i++)
	{
		if (a % i == 0) {
			arr1[count1] = i;
			count1++;
		}
	}
	for (int i = 1; i <= b; i++)
	{
		if (b % i == 0) {
			arr2[count2] = i;
			count2++;
		}
	}
	for (int i = 1; i <= c; i++)
	{
		if (c % i == 0) {
			arr3[count3] = i;
			count3++;
		}
	}
	count1--;
	count2--;
	count3--;

	//algorithm
	for (int i = 1; i <= count1; i++)
	{
		temp = arr1[i];
		for (int j = 1; j <= count2; j++)
		{
			if (temp == arr2[j]) {
				for (int k = 1; k <= count3; k++)
				{
					if (arr2[j] == arr3[k]) {
						result = temp;
						break;
					}
					if (k == count3) {
						continue;
					}
				}
			}
			if (j == count2) {
				continue;
			}
			if (result == temp)break;
		}
		if (i == count1) {
			printf("%d", result);
			return 0;
		}
	}
	
	return 0;
}