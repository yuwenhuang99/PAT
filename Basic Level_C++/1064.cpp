#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	bool friends[40];
	memset(friends, 0, sizeof(friends));
	int n, res = 0;
	string num;
	cin >> n;
	while (n--)
	{
		cin >> num;
		int ans = 0;
		for (auto i : num) ans += (i - '0');
		if (friends[ans] == 0) res++;
		friends[ans] = 1;
	}
	cout << res << endl;
	bool f = false;
	for (int i = 0;i < 40;++i) {
		if (friends[i]) {
			cout << (f ? " " : "") << i;
			f = true;
		}
	}
	return 0;
}