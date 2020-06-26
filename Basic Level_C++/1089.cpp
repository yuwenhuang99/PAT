/*第一反应，好像很难的样子啊，下一题。然后拖到现在最后一题了。
再来看看。好像数据量不大诶，而且只有两个狼人，那么暴力也就O(n*n),
找出了狼人看是否符合论述，要在遍历一遍，那么就是O(n^3)。n才100，可以过诶
于是乎，暴力吧。
*/
#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>v(n + 5);
	for (int i = 1;i <= n;++i) cin >> v[i];
	for (int i = 1;i <= n;++i) {
		for (int j = i + 1;j <= n;++j) {
			int lie = 0, WolfLie = 0;
			for (int k = 1;k <= n;++k) {
				if (v[k] < 0) {
					if (-v[k] != i && -v[k] != j) {
						lie++;
						if (k == i || k == j) WolfLie++;
					}
				}
				else if (v[k] == i || v[k] == j) {
					lie++;
					if (k == i || k == j) WolfLie++;
				}
			}
			if (lie == 2 && WolfLie == 1) {//注意一定有一个狼人撒谎！
				cout << i << " " << j << endl;
				return 0;
			}
		}
	}
	cout << "No Solution" << endl;
	return 0;
}