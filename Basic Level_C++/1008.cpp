#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	m %= n;
	int* num = new int[n];
	for (int i = 0;i < n;++i) cin >> num[i];
	//右移先整体翻转，左移最后整体翻转
	reverse(num, num + n);
	reverse(num, num + m);
	reverse(num + m, num + n);
	for (int i = 0;i < n;++i)
		cout << (i ? " " : "") << num[i];
	return 0;
}