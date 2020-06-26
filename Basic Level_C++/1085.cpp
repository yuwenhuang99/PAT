#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef pair<int, double> pid;//int是人数，double是分数，分数是最后存入SchInfo才取整，直接取整测试点5会wa
typedef struct SchInfo {
	int count;
	int totalscore;
	string name;
	SchInfo() { count = totalscore = 0;name = ""; }
	SchInfo(int _count, int _totalscore, string _name) : count(_count), totalscore(_totalscore), name(_name) {}
};
void Transform(char  c, double& grade) {//分数转换，引用
	if (c == 'B') grade /= 1.5;
	else if (c == 'T') grade *= 1.5;
}
void ToLower(string& s) {//记得要改成小写
	for (auto& i : s) i = tolower(i);
}
bool cmp(SchInfo a, SchInfo b) {//排序，怎么说怎么来
	if (a.totalscore != b.totalscore) return a.totalscore > b.totalscore;
	if (a.count != b.count) return a.count < b.count;
	return a.name < b.name;
}
int main() {
	//freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int n;
	string id, name;
	double grade;
	cin >> n;
	vector<SchInfo>ans;
	map<string, pid>school;//这样可以把学校名与（人数，分数）对应
	for (int i = 0;i < n;++i) {
		cin >> id >> grade >> name;
		Transform(id[0], grade);
		ToLower(name);
		school[name].first++;
		school[name].second += grade;
	}
	for (auto it : school) ans.push_back(SchInfo(it.second.first, (int)(it.second.second), it.first));
	cout << ans.size() << endl;
	sort(ans.begin(), ans.end(), cmp);
	int rank = 0, pre_score = -1;
	for (int i = 0;i <ans.size();++i) {
		if (pre_score != ans[i].totalscore) rank=i+1;//与前面的分数不同，则名次为i+1
		pre_score = ans[i].totalscore;//要记得更新
		cout << rank << " " << ans[i].name << " " << ans[i].totalscore << " " << ans[i].count << endl;
	}
	return 0;
}