/*1.大数加法
  2.判断回文数
  */
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool Judge(string a);//判断是否是回文数
string Add(string a, string b); //模拟大数加法
int main() {
	string a, b, sum;
	cin >> a;
	int k = 10;
	while (k-- > 0) {
		if (Judge(a)) {
			cout << a << " is a palindromic number." << endl;
			return 0;
		}
		b = a;
		reverse(b.begin(), b.end());
		cout << a << " + " << b << " = ";
		a = Add(a, b);
		cout << a << endl;
	}
	cout << "Not found in 10 iterations." << endl;
	return 0;
}
bool Judge(string a) {
	for (int i = 0;i < a.length() / 2;++i)
		if (a[i] != a[a.length() - i - 1]) return false;
	return true;
}
string Add(string a, string b) {
	string sum = "";//和
	int op = 0, tmp = 0, len = a.length();//进位,当前和,长度
	for (int i = len - 1;i >= 0;--i) {//模拟一下加法就好了
		tmp = a[i] + b[i] - '0' - '0' + op;
		a[i] = tmp % 10 + '0';
		op = tmp / 10;
	}
	if (op == 1) sum = "1";//当最高位进位，还要加个1哦
	return sum + a;
}