#include<iostream>
#include<cstring>
using namespace std;
int how_many[200];
int main()
{
	ios::sync_with_stdio(false);
	memset(how_many, 0, sizeof(how_many));
	int n,grade;
	cin >> n;
	while (n--)
	{
		cin >> grade;
		how_many[grade]++;
	}
	cin >> n;
	while (n--)
	{
		cin >> grade;
		cout << how_many[grade];
		if (n) cout <<  " ";
	}
	return 0;
}