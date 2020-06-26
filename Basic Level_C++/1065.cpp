#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	map<string, string>mp;//夫妻
	map<string, bool>is_exist;//是否出现
	vector<string> v;
	vector<string>ans;
	cin >> n;
	string s1, s2;
	while (n--)
	{
		cin >> s1 >> s2;
		mp[s1] = s2;
		mp[s2] = s1;
	}
	cin >> n;
	while (n--)
	{
		cin >> s1;
		v.push_back(s1);
		is_exist[s1] = 1;
	}
	for (auto s : v) {
		if (is_exist[mp[s]]==0) ans.push_back(s);//如果不是成对的放入ans
	}
	sort(ans.begin(), ans.end());//记得要排序
	cout << ans.size() << endl;
	for (auto s : ans) {
		if (s != *ans.begin()) cout << " ";
		cout << s;
	}
	return 0;
}