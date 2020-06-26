#include<cstdio>
using namespace std;
int main()
{
	int c1, c2;
	scanf("%d%d", &c1, &c2);
	int seconds = (int)((c2 - c1)/100.0+0.5);
	int minutes = seconds / 60;
	int hours = minutes / 60;
	seconds %= 60;
	printf("%02d:%02d:%02d\n", hours, minutes%60, seconds);
	return 0;
}