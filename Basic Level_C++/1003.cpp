/*难点就是第三点
  我们以初始状态进行迭代 aPbTc每迭代一次中间要加个A，后面要加a。又因为初始状态a*1=c，所以得到a*b=c
  其中b!=0
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n;
	cin >> n;
	getchar();
	char str[1005];
	while (n--)
	{
		cin.getline(str, 1005, '\n');
		int l = strlen(str);
		int len[3] = { 0 }, cnt = 0;//len[0,1,3]分别表示在P前A的数量，P与T中A的数量,T后的数量
		bool f = false;
		int P,T;
		P = T = 0;
		for (int i = 0;i < l;++i)
		{
			if (!(str[i] == 'P' || str[i] == 'T' || str[i] == 'A')) break;
			if (str[i] == 'P')
			{
				P++;
				len[0] = cnt;
				cnt = 0;
			}
			else if (str[i] == 'T')
			{
				T++;
				len[1] = cnt;
				cnt = 0;
			}
			else
				cnt++;
		}
		len[2] = cnt;
		//P,T都只能出现一次，P与T中必须有A
		if (P == 1 && T == 1 && len[1] && len[0] * len[1] == len[2]) f = true;
		if (f) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}