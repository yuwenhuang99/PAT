#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int n, m;
	int a, b;
	cin >> n >> m;
	map<int, vector<int> > mp;
	/*意思是每个int与一个vector数组里面所有的元素建立映射，也就是一对多
	如果知识一对一 可能出现key一样，value不一样，而原来的value会被覆盖*/
	while (n--)
	{
		cin >> a >> b;
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	while (m--)
	{
		vector<int> g;
		map<int, bool>is_exist;
		bool f = false;
		cin >> n;
		for (int i = 0;i < n;++i) {
			cin >> a;
			is_exist[a] = 1;
			g.push_back(a);
		}
		for (int i = 0;i < n;++i)
			for (auto j = 0;j < mp[g[i]].size();++j)
				if (is_exist[mp[g[i]][j]]) 	f = true;//找了就break可以快100ms，但为了代码简便一点，就不加了
		puts(f ? "No" : "Yes");
	}
	return 0;
}