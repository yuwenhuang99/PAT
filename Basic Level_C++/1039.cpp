#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	string str, sub;
	int how_many[200];
	memset(how_many, 0, sizeof(how_many));
	cin >> str >> sub;
	bool f = true;
	int res = 0;
	for (int i = 0;i < str.length();++i) how_many[str[i]]++;
	for (int i = 0;i < sub.length();++i)
	{
		if (how_many[sub[i]]) how_many[sub[i]]--;
		else	res++;
	}
	if (res == 0) cout << "Yes " << str.length() - sub.length() << endl;
	else cout << "No " << res << endl;
	return 0;
}