#include<iostream>
#include <string>
using namespace std;
inline void GetZeroAndOne(int n)
{
	int cnt1 = 0, cnt0 = 0;
	while (n > 0)
	{
		if (n & 1) cnt1++;
		else cnt0++;
		n = n >> 1;
	}
	cout << cnt0 << " " << cnt1 << endl;
}
int main()
{
	ios::sync_with_stdio(false);
	string str;
	getline(cin, str);
	int ans = 0;
	for (auto i : str)
		if (isalpha(i)) ans += (tolower(i) - 'a' + 1);
	GetZeroAndOne(ans);
	return 0;
}