#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, m, q;
	int Max = 0;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0;i < m;++i) {
		for (int j = 0;j < n;++j) {
			cin >> q;
			v[j] += q;
			if (Max < v[j]) Max = v[j];
		}
	}
	cout << Max << endl;
	bool f = false;
	for (auto i = v.begin();i != v.end();++i) {
		if (*i == Max) {
			cout << (f ? " " : "") << i - v.begin() + 1;
			f = true;
		}
	}
	cout << endl;
	return 0;
}