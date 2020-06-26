#include<iostream>
#include<cmath>
using namespace std;
void Print(int x, double y) {
	if (x > y) cout << " Gai";
	else if (x == y) cout << " Ping";
	else cout << " Cong";
}
int main() {
	int m, x, y;
	cin >> m >> x >> y;
	for (int a = 99;a >= 10;--a) {
		int b = a / 10 + (a % 10) * 10;
		double c = b * 1.0 / y;//丙的能力不一定是整数
		if (abs(a - b) == c * x) {
			cout << a;
			Print(m, a);Print(m, b);Print(m, c);
			return 0;
		}
	}
	puts("No Solution");
	return 0;
}