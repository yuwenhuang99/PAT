#include<iostream>
#include<cstring>
using namespace std;
//大数除法的简单情况，直接模拟就好
char divisor[1005];//除数
int dividend;//被除数
int quotient[1005];//商
void Division()
{
	int len = strlen(divisor);
	int now_divisor=0;
	int i = 0,j=0;
	while (i<len)
	{
		now_divisor = now_divisor * 10 + divisor[i] - '0';
		if (now_divisor >= dividend) {
			quotient[i] = now_divisor / dividend;
			now_divisor %= dividend;
		}
		else quotient[i] = 0;//当除数比被除数小，商可是要上0的哦，别忘记了
		++i;
	}
	if (quotient[j] == 0) j++;//第一位可能是0，所以不用输出
	while (j<i) cout << quotient[j++];
	if (i == 1 && quotient[0]==0) cout << "0";//这是除数比被除数小的情况
	cout << " " << now_divisor;//最后的除数就是余数了
}
int main()
{
	cin >> divisor >> dividend;
	Division();
	return 0;
}