#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int matrix[10000][100];
int t;
void Get(int& m, int& n) {
	for (int i = sqrt(t);i >= 1;--i)
		if (t % i == 0) {
			m = t / i, n = i;
			return;
		}
}
void Solve(int m, int n, vector<int>v) {
	int i = 0, j = -1, k = 0, p;
	/*这里我们假设起点是(0,-1)，那么问题就简单了一些。
	设每次的起点为(x,y)
	画图理解一下，是不是相当于每一次循环都填补了从(x,y+1)开始，
	到(x+1,y)为止，如此一来，变找行数，列数的规律就可以了
	*/
	while (k < t) {
		for (p = 0;p < n;++p) 	matrix[i][++j] = v[k++];//向左转
		for (p = 0;p < m - 1;++p) 	matrix[++i][j] = v[k++];//向下走
		m--, n--;//注意，这里往回走的时候，行数和列数都少了1，记住我们的起点是(0,-1)！！
		/*有没有发现其实是对称的*/
		for (p = 0;p < n;++p) 	matrix[i][--j] = v[k++];//向右转
		if (n == 0) return;//如果没有列了，就不要在上去了，不然覆盖了，注意1列的情况
		for (p = 0;p < m - 1;++p) 	matrix[--i][j] = v[k++];//向上走
		m--, n--;//每循环一次，列数少2，行数少2
	}
	/*文字太抽象，其实画个图就好理解很多了。*/
}
int main() {
	cin >> t;
	vector<int>v(t);
	for (int i = 0;i < t;++i) cin >> v[i];
	sort(v.begin(), v.end(), greater<int>());
	int n, m;
	Get(m, n);
	Solve(m, n, v);
	for (int i = 0;i < m;++i) {
		for (int j = 0;j < n;++j)
			cout << (j ? " " : "") << matrix[i][j];
		cout << endl;
	}
	return 0;
}