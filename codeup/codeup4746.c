#include <stdio.h>
int main()
{
	int a, b, c, n;
	scanf("%d %d %d", &a, &b, &c);
	scanf("%d", &n);
	while (1) {
		if (n >= 3600) {
			n -= 3600;
			a++;
		}
		else if (n >= 60) {
			n -= 60;
			b++;
		}
		else {
			c += n;
			break;
		}
	}
	if (c >= 60) {
		c -= 60;
		b++;
	}
	while (1) {
		if (b >= 60) {
			b -= 60;
			a++;
		}
		else break;
	}
	while (1) {
		if (a >= 24)a -= 24;
		else break;
	}

	printf("%d %d %d", a, b, c);

}
