#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int how_many[200];
inline bool Judge()
{
	return how_many['P'] || how_many['A'] || how_many['T'] || how_many['e'] || how_many['s'] || how_many['t'];
}
inline void Out(char c)
{
	if (how_many[c]) {
		cout << c;
		how_many[c]--;
	}
}
int main()
{
	memset(how_many, 0, sizeof(how_many));
	string str;
	cin >> str;
	for (int i = 0;i < str.length();++i)  how_many[str[i]]++;
	while (Judge())
		Out('P');Out('A');Out('T');Out('e');Out('s');Out('t');
	return 0;
}
