#include<iostream>
#include<cstring>
using namespace std;
bool Judge(int a, int b, int sum)
{
	if (a == sum && b != sum) return true;
	return false;
}
int main()
{
	int n;
	int a1, b1, a2, b2;
	int sum1 = 0, sum2 = 0;
	cin >> n;
	while (n--)
	{
		cin >> a1 >> b1 >> a2 >> b2;
		if (Judge(b1, b2, a1 + a2)) sum2++;
		if (Judge(b2, b1, a1 + a2)) sum1++;
	}
	cout << sum1 << " " << sum2 << endl;
	return 0;
}