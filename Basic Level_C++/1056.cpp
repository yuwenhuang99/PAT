#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n,num;
	int sum = 0;
	cin >> n;
	for (int i = 0;i < n;++i) {
		cin >> num;
		sum += num;
	}
	cout << sum * (n - 1) * 11 << endl;
	return 0;
}