#include<iostream>
using namespace std;
const int  maxn = 100005;
int school[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	int schoolid, score;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> schoolid >> score;
		school[schoolid] += score;
	}
	int res = 1;
	for (int i = 1; i <= n; ++i)
	{
		if (school[res] < school[i])
			res = i;
	}
	cout << res << ' ' << school[res] << endl;
	return 0;
}
