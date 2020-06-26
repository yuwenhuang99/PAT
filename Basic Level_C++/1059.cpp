#include<iostream>
#include<cstring>
#include<map>
#include<iomanip>
using namespace std;
const int N = 1e5;
bool is_prime[N + 5];
int Prime[N + 5];
void Euler()//素数打表 欧拉法
{
	is_prime[2] = 0;
	for (int i = 2, cnt = 0;i < N;++i)
	{
		if (is_prime[i] == 0) Prime[cnt++] = i;
		for (int j = 0;j < cnt && i * Prime[j] < N;++j) {
			is_prime[i * Prime[j]] = 1;
			if (i % Prime[j] == 0) break;
		}
	}
}
int is_exist[N + 5];//没出现过记为0，出现过记为1，访问后记为2，
int main()
{
	Euler();
	memset(is_exist, 0, sizeof(is_exist));
	map<int, int>mp;//用map记录名次，用数组也可以
	int n, id;
	cin >> n;
	for (int i = 1;i <= n;++i) {
		cin >> id;
		is_exist[id] = 1;
		mp[id] = i;
	}
	cin >> n;
	while (n--)
	{
		cin >> id;
		cout << setw(4) << setfill('0') << id << ": ";//记住要保证四位的格式
		if (is_exist[id] == 0) puts("Are you kidding?");//不存在
		else if (is_exist[id] == 1) {
			if (mp[id] == 1) puts("Mystery Award");//第一名
			else if (is_prime[mp[id]] == 0) puts("Minion");//素数名
			else puts("Chocolate");//其他
			is_exist[id] = 2;//标记为访问过
		}
		else  puts("Checked");//访问过的直接返回checked
	}
	return 0;
}