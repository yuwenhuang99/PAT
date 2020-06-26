#include<cstdio>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
struct Node {
	int val, wrong_ans;
	string options;
};
int main() {
	int n, m, c;
	int cnt, right_cnt;
	vector<Node> v(110);
	scanf("%d%d", &n, &m);
	for (int i = 0;i < m;++i) {
		scanf("%d%d%d", &v[i].val, &cnt, &right_cnt);
		getline(cin, v[i].options);
		v[i].wrong_ans = 0;
	}
	for (int i = 0;i < n;++i) {
		int sum = 0;
		for (int j = 0;j < m;++j) {
			string s = "";
			while ((c = getchar()) != '(');
			scanf("%d", &cnt);
			while ((c = getchar()) != ')') s += c; //空格怕啥，反正正确答案也有空格
			if (s != v[j].options) v[j].wrong_ans++;
			else sum += v[j].val;
		}
		printf("%d\n", sum);//0也要输出，开始测试点2一直过不去，原来是0分没有输出
	}
	int Max = 0;
	for (int i = 0;i < m;++i)
		if (v[i].wrong_ans > Max) Max = v[i].wrong_ans;
	if (Max == 0) {
		printf("Too simple\n");
		return 0;
	}
	printf("%d", Max);
	for (int i = 0;i < m;++i)
		if (Max == v[i].wrong_ans) printf(" %d", i + 1);
	return 0;
}