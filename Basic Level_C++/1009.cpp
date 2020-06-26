#include<iostream>
using namespace std;
int main()
{
	int num = 0;
	char ans[95][95];
	while (cin >> ans[num++] && getchar() != '\n');
	for (int i = num - 1;i >= 0;i--)
		cout << ans[i] << (i ? " " : "");
	return 0;
}
