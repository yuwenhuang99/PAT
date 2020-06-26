#include<iostream>
#include<algorithm>
using namespace std;
bool is_exist[10000] = { 0 };
void Func(int n)
{
	while (n != 1)
	{
		n = (n & 1) ? (3 * n + 1) / 2 : (n >> 1);
		if (is_exist[n]) return;
		is_exist[n] = 1;
	}
}
int main()
{
	int n, k, i = 0;
	int ans[105] = { 0 };
	cin >> k;
	while (k--)
	{
		cin >> n;
		if (is_exist[n]) continue;
		ans[i++] = n;
		Func(n);
	}
	sort(ans, ans + i, greater<int>());
	bool f = 0;
	for (int j = 0;j < i;++j)
	{
		if (!is_exist[ans[j]])
		{
			cout << (f ? " " : "") << ans[j];
			f = 1;
		}
	}
	return 0;
}