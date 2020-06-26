#include<iostream>
using namespace std;
inline int Getmod(int n) {//获取k的位数，以此得到mod的值 如k=92,mod=100
	int mod = 1;
	while (n) {
		mod *= 10;
		n /= 10;
	}
	return mod;
}
int main() {
	int m, n, k;
	cin >> m;
	while (m--)
	{
		cin >> k;
		int mod = Getmod(k);
		bool f = true;
		for (int i = 1;i < 10;++i) {
			if ((i * k * k) % mod == k) {
				f = false;
				cout << i << " " << i * k * k << endl;
				break;
			}
		}
		if (f) cout << "No" << endl;
	}
	return 0;
}