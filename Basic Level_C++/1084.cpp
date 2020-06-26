#include<iostream>
#include<string>
//与1078字符串压缩与解压类似，只不过1也要输出。
using namespace std;
string Generate(string s) {
	string tmp = "";
	int cnt = 1;
	char pre = s[0];
	for (int i = 1;i < s.length();++i) {
		if (s[i] == pre) cnt++;
		else {
			tmp += pre + to_string(cnt);
			pre = s[i];
			cnt = 1;
		}
	}
	return tmp + pre + to_string(cnt);//最后一个元素不论相不相同，都无法加入，因为已经遍历完了，所以要加上这个
}
int main() {
	string ans;
	int n;
	cin >> ans >> n;
	while (--n > 0) ans = Generate(ans);//是--n哦，因为n从1开始,
	cout << ans << endl;
	return 0;
}