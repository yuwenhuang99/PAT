#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int* score = new int[m];
	int* ans = new int[m];
	for (int i = 0;i < m;++i) cin >> score[i];
	for (int i = 0;i < m;++i) cin >> ans[i];
	int choice;
	while (n--)
	{
		int res = 0;
		for (int i = 0;i < m;++i) {
			cin >> choice;
			if (ans[i] == choice) res += score[i];
		}
		cout << res << endl;
	}
	delete[]score;
	delete[]ans;
	return 0;
}