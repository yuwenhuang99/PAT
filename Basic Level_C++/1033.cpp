#include<iostream>
#include<string>
#include<cstring>
using namespace std;
bool is_exist[200];
bool Judge(char c)
{
	//当c是大写字母 要'+'与其小写字母同时不坏才可以
	if (isupper(c))  return is_exist['+'] == 0 && is_exist[tolower(c)] == 0;
	return is_exist[c] == 0;
}
int main()
{
	ios::sync_with_stdio(false);
	memset(is_exist, 0, sizeof(is_exist));
	string badkey, inkey;
	getline(cin, badkey);
	getline(cin, inkey);
	for (int i = 0;i < badkey.length();++i)
	{
		if (isupper(badkey[i])) badkey[i] = tolower(badkey[i]);
		is_exist[badkey[i]] = 1;
	}
	for (int i = 0;i < inkey.length();++i)
		if (Judge(inkey[i])) cout << inkey[i];
	cout << endl;
	return 0;
}