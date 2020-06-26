#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*简单分析一下，如果从最大到小的结绳，那么绳子肯定越来越短，反之越来越长
因为最先结的绳子除2次数肯定比后结的多
所以 排序，然后计算就可以了*/
int main() {
	int n,len;
	vector<int>v;
	cin >> n;
	while (n--){
		cin >>v[0];
		v.push_back(len);
	}
	sort(v.begin(), v.end());
	double ans = v[0];
	for (auto i = 1;i<v.size();++i) 
		ans = (ans + v[i]) / 2.0;
	cout << int(ans) << endl;
	return 0;
}