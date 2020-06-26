#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	int n, d,k;
	double e,count;
	cin >> n >> e >> d;
	int certain = 0, possible = 0;
	for (int i = 0;i < n;++i) {
		cin >> k;
		int cnt = 0;//²»×ãÌìÊı
		for (int j = 0;j < k;++j) {
			cin >> count;
			if (count < e) cnt++;
		}
		if (cnt > k / 2) {
			if (k > d) certain++;
			else possible++;
		}
	}
	cout << setprecision(1) << fixed << possible * 100.0/n << "% ";
	cout<< setprecision(1) << fixed << certain * 100.0/n << "%"<<endl;
	return 0;
}