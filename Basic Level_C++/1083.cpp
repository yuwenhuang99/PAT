#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int main() {
	int n, num;
	cin >> n;
	int* ans = new int[n];
	memset(ans, 0, sizeof(ans));
	for (int i = 1;i <= n;++i) {
		cin >> num;
		ans[abs(num - i)]++;
	}
	for (int i = n - 1;i >= 0;--i)
		if (ans[i] > 1)
			cout << i << " " << ans[i] << endl;
	delete[]ans;
	return 0;
}