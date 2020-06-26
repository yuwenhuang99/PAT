#include<iostream>
#include<algorithm>
using namespace std;
/*直接对爱丁顿数的取值二分就好了
  但要注意一个情况，当此时的爱丁顿数比天数小，那么这个爱丁顿数也是可以的。
  例如5 5 10 10 10 10。答案是4，因为5不满足，4则有5天满足，那么爱丁顿数是4
  */
int Binary_Search(int dis[], int n) {
	int l = 0, r = dis[n - 1];
	int ans = 0;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		int tmp = n - (upper_bound(dis, dis + n, mid) - dis);//大于mid的个数
		if (mid == tmp) {
			ans = max(tmp, ans);
			l = mid + 1;
		}
		else if (mid < tmp) {//因为此时也会得到答案，因为mid<tmp,代表爱丁顿数可以取mid，但不一定最优
			l = mid + 1;
			if (mid > ans) ans = mid;
		}
		else  r = mid - 1;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int n;
	cin >> n;
	int* dis = new int[n];
	for (int i = 0;i < n;++i)
		cin >> dis[i];
	sort(dis, dis + n);
	cout << Binary_Search(dis, n) << endl;
	delete[]dis;
	return 0;
}