#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int Getlimit(int n)
{
	int a[4] = { n / 1000,n / 100 % 10,n / 10 % 10,n % 10 };
	int Max = 0, Min = 0;
	sort(a, a + 4);
	for (int i = 0;i < 4;++i) {
		Min = Min * 10 + a[i];
		Max = Max * 10 + a[3 - i];
	}
	printf("%04d - %04d = %04d\n", Max, Min, Max-Min);
	return Max - Min;
}
int main()
{
	int n;
	scanf("%d", &n);
	do
	{
		n=Getlimit(n); 
	} while (n != 6174 && n != 0);
	return 0;
}