#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int a[10];
	for (int i = 0;i < 10;++i) cin >> a[i];
	char ans[100];
	memset(ans, 0, sizeof(ans));
	int cnt = 0;
	//先放最高位，因为它不能为0
	for(int i=1;i<10;++i) 
		if (a[i])
		{
			ans[cnt++] = i+'0';
			a[i]--;
			break;
		}
	for (int i = 0;i < 10;++i)
	{
		while (a[i])
		{
			ans[cnt++] = i+'0';
			a[i]--;
		}
	}
	puts(ans);
	return 0;
}