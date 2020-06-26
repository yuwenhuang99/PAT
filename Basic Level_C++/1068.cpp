/*这题目开始会错意了。结果样例都不对
我开始以为是简单的求和，就是把该点周围的八个点与他的和都加起来，没超过tol就不算。然后求最大值，看最大值是否只有一个。
然而！！！错的。。。之后看了下其他人的分析，恍然大悟
原来，这个点颜色值必须是唯一的，而且与周围点的差值都大于tol。满足这样的点就可以，不用求最大值！！！！
傻了呀，题目都没看明白。。懂了题意之后就很简单了，可以用map保证该点唯一。然后就没啥了。
*/
#include<cstdio>
#include<cmath>
#include<map>
using namespace std;
int matrix[1055][1055];
int	m, n, tol;
int dis[8][2] = { {1,1},{1,0},{1,-1},{-1,1},{-1,0},{-1,-1},{0,1},{0,-1} };//八个方位
inline bool Judge(int x, int y) {//判断是否越界
	return x < n&& x >= 0 && y < m&& y >= 0;
}
bool is_beyond(int a, int b) {//以该点为中心的颜色差值
	for (int i = 0;i < 8;++i) {
		int now_x = a + dis[i][0];
		int now_y = b + dis[i][1];
		if (Judge(now_x, now_y) && (abs(matrix[a][b] - matrix[now_x][now_y]) <= tol))
			return false;
	}
	return true;
}
int main() {
	int x, y, cnt = 0;
	map<int, int>mp;
	scanf("%d%d%d", &m, &n, &tol);
	for (int i = 0;i < n;++i)
		for (int j = 0;j < m;++j) {
			scanf("%d", &matrix[i][j]);
			mp[matrix[i][j]]++;
		}
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < m;++j) {
			if (mp[matrix[i][j]] == 1 && is_beyond(i, j)) {
				cnt++;
				if (cnt > 1) {
					puts("Not Unique");
					return 0;
				}
				x = i, y = j;
			}
		}
	}
	if (cnt == 0) puts("Not Exist");
	else printf("(%d, %d): %d\n", y + 1, x + 1, matrix[x][y]);
	return 0;
}