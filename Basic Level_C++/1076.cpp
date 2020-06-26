#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n;
	char q, c, op;
	string ans = "";
	cin >> n;
	while (n--)
	{
		for (int i = 0;i < 4;++i) {
			cin >> q >> op >> c;
			if (c == 'T') ans += (q - 'A' + '1');
		}
	}
	cout << ans << endl;
	return 0;
}