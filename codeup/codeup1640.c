#include <stdio.h>
char arr[101][1001] = { 0 };
int main() {
	int n,count=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("\n%[^\n]s", arr[i]);
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 1001; j++)
		{
			if (arr[i][j] == '\0')
				if (j <= 3) {
					printf("%s\n", arr[i]);
					count++;
					break;
				}
				else break;
			if (arr[i][j] == 't' && arr[i][j + 1] == 'a' && arr[i][j + 2] == 'p') {
				printf("%s\n", arr[i]);
				count++;
				break;
			}
			if (arr[i][j] == 'x' && arr[i][j + 1] == 'o' && arr[i][j + 2] == 'c'
				&& arr[i][j + 3] == 'u' && arr[i][j + 4] == 'r' && arr[i][j + 5] == 'e') {
				printf("%s\n", arr[i]);
				count++;
				break;
			}
		}
	}
	if (count >= 7)printf("danger");
	else if (count >= 4)printf("warning");
	else printf("safe");

	return 0;
}