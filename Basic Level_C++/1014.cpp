#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
using namespace std;
char str[70], str1[70];
//有些几个地方有些坑，不过不难。
int get_num(char c)//小时的转化
{
	if (c >= '0' && c <= '9') return c - '0';
	return c - 'A' + 10;
}
void Get_day_and_hour(int& day, int& hour);
void Get_minute(int& minute);
int main()
{
	char days[8][5] = { "",{"MON"},{"TUE"},{"WED"},{"THU"},{"FRI"},{"SAT"},{"SUN"} };
	int day, hour, minute;
	Get_day_and_hour(day, hour);
	Get_minute(minute);
	cout << days[day] << " ";
	cout << setw(2) << setfill('0') << hour<<":";
	cout << setw(2) << setfill('0') << minute<<endl;
	return 0;
}
void Get_day_and_hour(int& day, int& hour)
{
	cin >> str >> str1;
	for (int i = 0, k = 0;i < min(strlen(str), strlen(str1));++i)
	{
		if (k == 0 && str[i] == str1[i] && (str[i] >= 'A' && str[i] <= 'G'))//不是所有大写字母 只有7个，从A->G
		{
			day = str[i] - 'A' + 1;
			k++;
		}
		//找到day后再找时间，同时也不是所有大写字母是从A->N，0-9。不然会有两个样例过不了
		else if (k > 0 && str[i] == str1[i] && ((str[i] >= 'A' && str[i] <= 'N') || (str[i] >= '0' && str[i] <= '9')))
		{
			hour = get_num(str[i]);
			break;
		}
	}
}
void Get_minute(int& minute)
{
	cin >> str >> str1;
	for (int i = 0;i < min(strlen(str), strlen(str1));++i)
	{
		if (str[i] == str1[i] && isalpha(str[i]))
		{
			minute = i;
			break;
		}
	}
}