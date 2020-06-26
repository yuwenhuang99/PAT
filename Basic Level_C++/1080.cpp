#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
struct StuInfo {
	string id;
	int Gp, Gmid_term, Gfinal, G;
	StuInfo(string _id, int _Gp) { id = _id;Gp = _Gp;Gmid_term = Gfinal = G = -1; }
};
bool cmp(StuInfo a, StuInfo b) {
	return (a.G == b.G) ? a.id < b.id : a.G > b.G;
}
int main() {
	//ios::sync_with_stdio(false);cin.tie(0);
	//freopen("in.txt", "r", stdin);
	int p, m, n;
	string id;
	int grade, cnt = 0;
	vector<StuInfo>stu_info;
	map<string, int>mp;
	cin >> p >> m >> n;
	while (p--) {
		cin >> id >> grade;
		stu_info.push_back(StuInfo(id, grade));
		mp[id] = cnt++;
	}
	for (int i = 0;i < m;++i) {
		cin >> id >> grade;
		if (mp.find(id) != mp.end())
			stu_info[mp[id]].Gmid_term = grade;
	}
	//同上
	for (int i = 0;i < n;++i) {
		cin >> id >> grade;
		if (mp.find(id) != mp.end())
			stu_info[mp[id]].Gfinal = grade;
	}
	//保存总成绩，记得要用引用哦
	for (auto& i : stu_info) {
		if (i.Gmid_term > i.Gfinal)
			i.G = int(i.Gmid_term * 0.4 + i.Gfinal * 0.6 + 0.5);
		else i.G = i.Gfinal;
	}
	sort(stu_info.begin(), stu_info.end(), cmp);
	for (auto i : stu_info)
		if (i.G >= 60 && i.Gp >= 200)
			cout << i.id << " " << i.Gp << " " << i.Gmid_term << " " << i.Gfinal << " " << i.G << endl;
	return 0;
}