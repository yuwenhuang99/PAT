#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
int main()
{
	int n, x;
	int a[6], a4_sum = 0;
	memset(a, 0, sizeof(a));
	int op = 1;
	bool f = 0;
	cin >> n;
	while (n--)
	{
		cin >> x;
		if (x % 10 == 0) a[1] += x;
		else if (x % 5 == 1) {
			a[2] += x * op;
			op = -op;
			f = 1;
		}
		else if (x % 5 == 2) a[3]++;
		else if (x % 5 == 3)
		{
			a[4] ++;
			a4_sum+=x;
		}
		else if (x % 5 == 4)
		{
			if (x > a[5]) a[5] = x;
		}
	}
	for (int i = 1;i <= 5;++i)
	{
		if (i > 1) cout << " ";
		if (a[i]==0&&((i==2&&f==0)||(i!=2))) cout << "N";//注意a[2]可能恰好为0，但也要输出的情况
		else {
			if (i == 4) cout << fixed << setprecision(1) << (a4_sum*1.0/a[4]);
			else cout << a[i];
		}
	}
	return 0;
}