#include <stdio.h>
#include <math.h>
int main() {
	int first_money, day, data[11] = { 0 };
	double last_money;
	scanf("%d", &first_money);
	double money = first_money;
	scanf("%d", &day);
	for (int i = 0; i < day; i++)
	{
		scanf("%d", &data[i]);
	}
	for (int i = 0; i < day; i++)
	{
		int variance = data[i];
		double a = money / 100;
		money += a* variance;
	}
	last_money = money - first_money;
	if (last_money > 0)last_money = floor(last_money + 0.5);
	else last_money = ceil(last_money - 0.5);
	if (last_money == -0)last_money *= -1;
	printf("%.0lf\n", last_money);
	if (last_money > 0)printf("good");
	else if (last_money < 0)printf("bad");
	else printf("same");

	return 0;
}