#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char str[1005];
	cin >> str;
	int len = strlen(str);
	int a[10];
	memset(a, 0, sizeof(a));
	for (int i = 0;i < len;++i) a[str[i] - '0']++;
	for (int i = 0;i < 10;++i)
		if (a[i]) cout << i << ":" << a[i] << endl;
	return 0;
}