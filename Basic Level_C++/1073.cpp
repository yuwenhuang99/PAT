#include<cstdio>
#include<vector>
using namespace std;
struct Node {
	int score, cnt;
	bool is_true[6];
};
int main() {
	int n, m, score, ops, Max_error = 0;
	char c;
	int Error[105][6] = { 0 };
	double sum[1024] = { 0 };
	/*输入选项*/
	scanf("%d%d", &n, &m);
	vector<Node>op(m);
	for (int i = 0;i < m;++i) {
		scanf("%d%*d%d", &score, &ops);
		op[i].score = score;
		op[i].cnt = ops;
		for (int j = 0;j < ops;++j) {
			scanf(" %c", &c);
			op[i].is_true[c - 'a'] = 1;
		}
	}
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < m;++j) {
			bool f = true;//是否出现答案中没有的选项
			bool is_in[6] = { 0 };//记录学生的答案
			while ((c = getchar()) != '(');
			scanf("%d", &ops);
			while ((c = getchar()) != ')') /*输入学生的答案*/
				if (c != ' ')
				{
					is_in[c - 'a']++;
					if (op[j].is_true[c - 'a'] == 0) f = false;//如果有不属于的，那么一定是错的
				}
			/*注意，错误选项有两种情况，答案有但没选，答案没有但选了*/
			for (int k = 0;k < 5;++k) {
				if (is_in[k] != op[j].is_true[k]) Error[j][k]++;/*两个不相等就说明肯定不行*/
				if (Error[j][k] > Max_error) Max_error = Error[j][k];
			}
			/*如果回答选项都在正确选项里，而且选的个数也一样肯定对*/
			if (f) sum[i] += (op[j].cnt == ops) ? op[j].score * 1.0 : op[j].score / 2.0;
		}
	}
	for (int i = 0;i < n;++i)	printf("%.1f\n", sum[i]);
	if (Max_error == 0) { printf("Too simple\n");return 0; }
	for (int i = 0;i < m;++i) /*这是输出错误最多的选项*/
		for (int j = 0;j < 5;++j)
			if (Error[i][j] == Max_error)
				printf("%d %d-%c\n", Max_error, i + 1, j + 'a');
	return 0;
}