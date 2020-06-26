#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
using namespace std;
bool Judge(string a, double& tmp);//判断是否是合法的输入
int main() {
	int n, cnt = 0;
	cin >> n;
	string num[200];
	double ans = 0, tmp;
	for (int i = 0;i < n;++i) cin >> num[i];
	for (int i = 0;i < n;++i) {
		if (Judge(num[i], tmp)) {
			ans += tmp;
			cnt++;
		}
		else cout << "ERROR: " << num[i] << " is not a legal number" << endl;
	}
	cout << "The average of " << cnt << ((cnt == 1) ? " number is " : " numbers is ");//注意1的时候是number
	if (cnt == 0) cout << "Undefined" << endl;
	else cout << setprecision(2) << fixed << ans / cnt << endl;
	return 0;
}
bool Judge(string a, double& tmp) {//引用，如果是a合法，可以返回该实数
	bool f = false;//是否出现'.'
	for (int i = 0;i < a.length();++i) {
		if (isalpha(a[i])) return false;//有字母
		if (f && a[i] == '.') return false;//出现两个'.'
		if (a[i] == '.') {
			f = true;
			if (a.length() - i > 3) return false;//小数点后超过两位
		}
	}
	tmp = atof(a.c_str());//是一个实数，把他转换成浮点数，再判断是否在范围内
	return fabs(tmp) <= 1000.00;
}