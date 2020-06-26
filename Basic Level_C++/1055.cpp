#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
struct Node {
	int high;
	string name;
	Node() {}
	Node(int a, string b) :high(a), name(b) {}
};
vector<Node>v;
int n, k, h;
bool cmp(Node a, Node b) { return (a.high == b.high) ? a.name<b.name : a.high>b.high; }
void SortPeople() {
	int cnt = n / k;
	int last_cnt = cnt + n % k;
	for (int i = 0, p = 0;i < k;++i) {
		int mid, now_cnt;
		now_cnt = ((i == 0) ? last_cnt : cnt);
		vector<string>ans(now_cnt + 5);
		mid = now_cnt / 2 + 1;
		ans[mid] = v[p++].name;
		for (int j = 1, f = -1, len = 0;j < now_cnt;++j) {
			if (j & 1) len++;
			ans[mid + f * len] = v[p++].name;
			f = -f;
		}
		//输出,注意下标从1开始
		for (int q = 1;q <= now_cnt;++q)
			cout << (q > 1 ? " " : "") << ans[q];
		cout << endl;
	}
}
int main() {
	string name;
	cin >> n >> k;
	for (int i = 0;i < n;++i) {
		cin >> name >> h;
		v.push_back(Node(h, name));
	}
	sort(v.begin(), v.end(), cmp);
	SortPeople();
	return 0;
}