#include<cstdio>
#include<cstring>
typedef long long ll;
const int mod = 1000000007;
const int N = 1e5;
/*开始用了两个数组分别保存P,T的数量
然后优化到只用一个数组保存T
最后看了柳神的代码，发现用个变量保存T就好
空间复杂度还能优化吗？*/
int main() {
	char s[N + 5];
	ll ans = 0, pre_P = 0, next_T = 0;
	scanf("%s", s );
	int len = strlen(s);
	for (int i = len - 1;i >= 0;--i)
		if (s[i] == 'T') next_T++;
	for (int i = 0;i < len;++i) {
		if (s[i] == 'P') pre_P++;
		else if (s[i] == 'T') next_T--;//表示前面出现T，那么后面就少了一个
		else if (s[i] == 'A') ans = (ans % mod + ((pre_P % mod * next_T % mod)) % mod) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}