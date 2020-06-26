#include<iostream>
#include<string>
using namespace std;
bool is_prime(int n) {
	for (int i = 2;i * i < n + 1;++i)
		if (n % i == 0) return false;
	return true;
}
int main() {
	int l, k, num;
	string str, sub;
	cin >> l >> k;
	cin >> str;
	bool f = true;
	for (int i = 0;i + k - 1 < l;++i) {
		sub = str.substr(i, k);
		num = stoi(sub);
		if (is_prime(num)) {
			cout << sub << endl;
			f = false;
			break;
		}
	}
	if (f) cout << "404" << endl;
}