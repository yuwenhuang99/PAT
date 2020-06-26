#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n, m;
	double g2, g1;
	cin >> n >> m;
	for (int i = 0;i < n;++i) {
		cin >> g2;
		int ans = 0,cnt=0;
		int Min = m + 5, Max = 0, score;
		for (int j = 1;j < n;++j) {
			cin >> score;
			if (score<0 || score>m) continue;
			if (score < Min) Min = score;
			if (score > Max) Max = score;
			ans += score;
			cnt++;
		}
		ans -= (Max + Min);
		g1 = ans * 1.0 / (cnt - 2);
		ans = ((g1 + g2) / 2.0+0.5);
		cout << ans << endl;
	}
	return 0;
}