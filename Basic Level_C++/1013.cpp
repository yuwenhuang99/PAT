#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e6 + 5;
bool is_prime[N];
int Prime[N];
void Euler()
{
	memset(is_prime, 0, sizeof(is_prime));
	int cnt = 1;
	for (int i = 2;i < N;++i)
	{
		if (cnt > 1e4) break;
		if (!is_prime[i]) Prime[cnt++] = i;
		for (int j = 1;j < cnt && i * Prime[j] < N;++j)
		{
			is_prime[i * Prime[j]] = 1;
			if (i % Prime[j] == 0) break;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	Euler();
	int n, m;
	cin >> m >> n;
	for (int i = m,k=0;i <= n;++i,++k)
	{
		if (k == 10) {
			cout << endl;
			k = 0;
		}
		else if (k) cout << " ";
		cout << Prime[i];
	}
	return 0;
}