#include<iostream>
#include<set>
using namespace std;
int Function(int n) { return n / 2 + n / 3 + n / 5; }
int main() {
	int n;
	set<int>s;
	cin >> n;
	for (int i = 1;i <= n;++i)
		s.insert(Function(i));
	cout << s.size() << endl;
	return 0;
}