#include<iostream>
#include<string>
using namespace std;
string ans = "";
void Zip(string s) {//压缩
	int cnt = 1;
	char c = s[0];
	for (int i = 1;i < s.length();++i) {
		if (s[i] == c) cnt++;
		else {
			if (cnt > 1) ans += to_string(cnt);/*1是默认的就不放进去了*/
			ans += c;
			c = s[i];
			cnt = 1;
		}
	}
	/*遍历完了，把没加的加进去，其实也就是最后一个和前面相同的情况*/
	if (cnt > 1) ans += to_string(cnt);
	ans += c;
	cout << ans << endl;
}
void Unzip(string s) {//解压
	for (int i = 0, cnt;i < s.length();++i) {
		cnt = 0;
		while (isdigit(s[i])) //是数字就一直读取，因为可能有两位数，三位数
			cnt = cnt * 10 + s[i++] - '0';
		do {//不用while是因为当cnt是0，表示只有一个，也要输出这一个字符
			ans += s[i];
		} while (--cnt > 0);
	}
	cout << ans << endl;
}
int main() {
	char c;
	string s;
	cin >> c;
	cin.ignore();//读取回车
	getline(cin, s);
	(c == 'C') ? Zip(s) : Unzip(s);
	return 0;
}