#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string str;
	int how_many[30];
	memset(how_many, 0, sizeof(how_many));
	getline(cin, str);
	for (int i = 0;i < str.length();++i)
		if (isalpha(str[i])) how_many[tolower(str[i]) - 'a']++;
	int res = 0;
	for (int i = 0;i < 26;++i)
		if (how_many[i] > how_many[res]) res = i;
	cout << char(res + 'a') << " " << how_many[res] << endl;
	return 0;
}