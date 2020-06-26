#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	string hex, a, b, ans;
	cin >> hex >> a >> b;
	int len1 = a.length() - 1, len2 = b.length() - 1, len3 = hex.length() - 1;
	int op = 0, carry = 0, k = 0;
	//模拟加法，如果位数不够，则视为加'0'
	while (len1 >= 0 || len2 >= 0)
	{              //len1,len2小于0，则视该位是'0'。知道a,b都遍历完
		int sum = ((len1 >= 0) ? a[len1] : '0') + ((len2 >= 0) ? b[len2] : '0') - '0' - '0' + carry;
		if (hex[len3] == '0' || hex[len3] == 'd') op = 10;//注意会出现'd'
		else op = hex[len3] - '0';
		ans += sum % op + '0';
		carry = sum / op;
		len1--;len2--;len3--;
	}
	if (carry) cout << carry;//当最高位有进位则要输出这个进位
	reverse(ans.begin(), ans.end());//翻转一下，可以正常输出了
	while (carry == 0 && ans[k] == '0' && k < ans.length() - 1)//要给ans留一位，不然答案为0没输出
		k++;//如果没有进位，且最高位是0，则不输出
	while (k < ans.length())
		cout << ans[k++];
	return 0;
}