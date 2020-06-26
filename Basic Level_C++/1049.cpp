#include<cstdio>
const int N = 1e5;
typedef long long ll;
//每个数字出现的次数为 Fi = Fi-1 - 2(i-1) + n 
//乖乖，再仔细看看，这个数列可以化简啊。累加得到 Fi = i(n-i+1)。好家伙。
inline double Quick_mul(double a, ll b) {
	double res = 0;
	while (b) {
		if (b & 1) res += a;
		a += a;
		b = b >> 1;
	}
	return res;
}
int main() {
	int n;
	scanf("%d", &n);
	double res = 0, x;
	ll pre_f = 0;
	for (int i = 1;i <= n;++i) {
		scanf("%lf", &x);
		pre_f += (ll)(n - 2 * (i - 1));
		//res += num[i] * pre_f;
		res += Quick_mul(x, pre_f);
	}
	printf("%.2f\n", res);
	return 0;
}