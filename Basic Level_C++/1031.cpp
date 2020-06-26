#include<iostream>
#include<cstring>
#include <vector>
using namespace std;
char ZToM[20] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4','3' ,'2' };
int Weight[20] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
int GetSum(string str)//获取z
{
	int sum = 0;
	for (int i = 0;i < 17;++i)
		sum = (sum % 11 + ((str[i] - '0') * Weight[i]) % 11) % 11;
	return sum % 11;
}
bool Judge(string str)//判断是否合法
{
	return ZToM[GetSum(str)] == str[17];
}
int main()
{
	int n;
	string str;
	vector<string>ans;
	cin >> n;
	while (n--)
	{
		cin >> str;
		if (!Judge(str)) ans.push_back(str);
	}
	if (ans.empty()) cout << "All passed" << endl;
	for (string s : ans) cout << s << endl;
	return 0;
}