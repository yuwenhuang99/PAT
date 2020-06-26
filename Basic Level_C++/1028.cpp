#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Per {
public:
	string name;
	int year, month, day;
	Per(string s, int a, int b, int c) : name(s), year(a), month(b), day(c) {}
	Per() {}
};
bool cmp(Per a, Per b)
{
	if (a.year != b.year) return a.year < b.year;
	if (a.month != b.month) return a.month < b.month;
	if (a.day != b.day) return a.day < b.day;
}
//2014 年 9 月 6 日
bool Judge(int y, int m, int d)
{
	if (y < 1814 || (y == 1814 && ((m < 9) || (m == 9 && d < 6)))) return false;
	if (y != 2014) return y < 2014;
	if (m != 9) return m < 9;
	return d <= 6;
}
int main()
{
	ios::sync_with_stdio(false);
	int n, cnt = 0;
	string name;
	char str[20];
	int y, m, d;
	cin >> n;
	Per* person = new Per[n];
	while (n--)
	{
		cin >> name;
		cin >> str;
		sscanf(str, "%d/%d/%d", &y, &m, &d);
		if (Judge(y, m, d))
			person[cnt++] = Per(name, y, m, d);
	}
	sort(person, person + cnt, cmp);
	//当没有人满足时要特判
	cout << cnt;
	if(cnt)	cout<<" " << person[0].name << " " << person[cnt - 1].name << endl;
	return 0;
}