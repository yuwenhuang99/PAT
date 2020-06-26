#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char s[1005];
int Transform(int sum, int d)//进制转换，并返回位数，方便翻转。
{
	int i = 0;
	do
	{
		s[i++] = sum % d + '0';
		sum /= d;
	}while (sum);//哪怕是0也要保存，不然没有输出
	return i;
}
int main()
{
	int a, b, d;
	cin >> a >> b >> d;
	int sum = a + b;
	reverse(s, s + Transform(sum, d));//也可以倒着输出
	puts(s);
	return 0;
}