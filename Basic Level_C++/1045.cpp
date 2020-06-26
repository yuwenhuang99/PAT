#include<iostream>
#include<cstring>
#include<set>
using namespace std;
const int N = 1e5;
int *num;
bool *Is_true;//记录是否正确
int main() {
	ios::sync_with_stdio(false);
	set<int>ans;
	int n;
	int Max = 0;
	cin >> n;
	num = new int[n];
	Is_true = new bool[n];
	memset(Is_true, 0, sizeof(Is_true));

	/*从左边开始，标记（符合左边元素都比他小这一条件）的元素，并记录当前的最大值，
	因为，每个主元都要比前面最大的元素都大
	*/
	for (int i = 0;i < n;++i) {
		cin >> num[i];
		if (num[i] > Max) {
			Is_true[i] = 1;
			Max = num[i];
		}
	}
	/*同理，从右边再扫描一遍，这时记录最小值，因为主元要比后面最小值都小*/
	int Min = 0x7f7f7f7f;
	for (int i = n - 1;i >= 0;--i) {
		if (Min > num[i]) {
			if (Is_true[i]) ans.insert(num[i]);//如果都满足，就是主元，懒得排序，直接丢set里面
			Min = num[i];
		}
	}
	bool f = false;
	cout << ans.size() << endl;
	for (auto i : ans) {
		cout << (f ? " " : "") << i;
		f = true;
	}
	//没有这个，测试点2会格式错误
	cout << endl;//有点坑，哪怕是0，也要输出一个换行，因为在第二行输出元素嘛，哪怕没有也要输出第二行
	delete[]num;
	delete[]Is_true;
	return 0;
}