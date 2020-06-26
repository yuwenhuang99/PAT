#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string a, b;
int l1, l2;
void Solve(int i)
{
	int  c;
	if (i & 1) {
		c = (a[l1 - i] + b[l2 - i] - '0' - '0') % 13;
		if (c < 10) b[l2 - i] = c + '0';
		else {
			if (c == 10) b[l2 - i] = 'J';
			else if (c == 11) b[l2 - i] = 'Q';
			else if (c == 12) b[l2 - i] = 'K';
		}
	}
	else {
		c = (b[l2 - i] - a[l1 - i] + 10) % 10;
		b[l2 - i] = c + '0';
	}
}
int main()
{
	cin >> a >> b;
	string str = "";
	l1 = a.length(), l2 = b.length();
	//当b的长度小于加密长度前面要补0，而且同时l2也要增加
	while (l1 - l2 > 0)
	{
		str += '0';
		l2++;
	}
	b = str + b;
	for (int i = 1;i <= l1;++i)
		Solve(i);
	cout << b << endl;
	return 0;
}