#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
ll GetSum(ll n, ll Dn)
{
	ll ans = 0;
	while (n)
	{
		if (n % 10 == Dn) ans = ans * 10 + Dn;
		n /= 10;
	}
	return ans;
}
int main()
{
	ll a, b, Da, Db;
	cin >> a >> Da >> b >> Db;
	ll res = GetSum(a, Da) + GetSum(b, Db);
	cout << res << endl;
	return 0;
}