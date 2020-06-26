#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
bool is_exist[300];
using namespace std;
void Mark(char c)//标记出现的字母或者下划线，注意字母的话大小写都要标记，因为大小写都是一个键
{
	is_exist[c] = 1;
	if (c >= 'a' && c <= 'z') is_exist[c - 'a' + 'A'] = 1;
	if (c >= 'A' && c <= 'Z') is_exist[c - 'A' + 'a'] = 1;
}
void Outchar(char c)
{
	if (c >= 'a' && c <= 'z') cout << (char)toupper(c);
	else cout << (char)c;
}
int main()
{
	memset(is_exist, 0, sizeof(is_exist));
	string str, sub;
	cin >> str >> sub;
	for (int i = 0;i < sub.length();++i)
		Mark(sub[i]);
	for (int i = 0;i < str.length();++i)
	{
		if (is_exist[str[i]] == 0)
		{
			Outchar(str[i]);
			Mark(str[i]);//不要重复输出，所以对输出的字符也标记一下
		}
	}
	cout << endl;
	return 0;
}