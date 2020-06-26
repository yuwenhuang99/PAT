#include<iostream>
#include<string>
#include<map>
using namespace std;
int main() {
	string name[1100];
	int m, n, s;
	map<string,bool>mp;
	cin >> m >> n >> s;
	for (int i = 1;i <= m;++i) cin >> name[i];
	if (s > m) {
		puts("Keep going...");
		return 0;
	}
	for (int i = s;i <= m;) {
		if (mp[name[i]] == 0) {
			cout << name[i] << endl;
			mp[name[i]] = 1;
			i += n;
		}
		else i++;
	}
	return 0;
}