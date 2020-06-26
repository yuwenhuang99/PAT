#include<iostream>
#include<cstring>
using namespace std;
bool Win(char a, char b)
{
	if (a == 'C' && b == 'J') return true;
	if (a == 'J' && b == 'B') return true;
	if (a == 'B' && b == 'C') return true;
	return false;
}
int main()
{
	int n;
	char a, b;
	int sum1 = 0, sum2 = 0;
	int p1[26], p2[26];
	int max1 = 0, max2 = 0;
	char c1='B', c2='B';
	memset(p1, 0, sizeof(p1));
	memset(p2, 0, sizeof(p2));
	cin >> n;
	for (int i = 0;i < n;++i)
	{
		cin >> a >> b;
		if (Win(a, b)) {
			p1[a - 'A']++;
			if (p1[a - 'A'] > max1 || (p1[a - 'A'] == max1 && a < c1)) {//如果一样多，要保存字典序小的
				max1 = p1[a - 'A'];
				c1 = a;
			}
			sum1++;
		}
		else if (Win(b, a)) {
			p2[b - 'A']++;
			if (p2[b - 'A'] > max2 ||(p2[b - 'A'] == max2&&b<c2)) {
				max2 = p2[b - 'A'];
				c2 = b;
			}
			sum2++;
		}
	}
	cout << sum1 << " " << n - sum1 - sum2 << " "<<sum2<<endl;
	cout << sum2 << " " << n - sum1 - sum2 <<" "<< sum1<<endl;
	cout << c1 << " " << c2 << endl;
	return 0;
}