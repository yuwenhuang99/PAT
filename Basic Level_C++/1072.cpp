#include<iostream>
#include<map>
#include<iomanip>
using namespace std;
int main() {
	int n, m, index;
	map<int, bool>mp;
	cin >> n >> m;
	while (m--) {
		cin >> index;
		mp[index] = 1;
	}
	string name;
	int cntStu = 0, cntObj = 0;
	while (n--) {
		cin >> name >> m;
		bool f = true;
		while (m--) {
			cin >> index;
			if (mp[index]) {
				if (f) cout << name << ":";
				f = false;
				cout << " " << setw(4) << setfill('0') << index;
				cntObj++;
			}
		}
		if (f == false) {
			cntStu++;
			cout << endl;
		}
	}
	cout << cntStu << " " << cntObj << endl;
	return 0;
}