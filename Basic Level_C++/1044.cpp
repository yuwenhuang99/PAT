#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string, string>mp;
string fir[13] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string sec[13] = {"","tam ","hel ","maa ","huh ","tou ","kes ","hei ","elo ","syy ","lok ","mer ","jou " };
void Pre_treatment()
{	
	int f, s;
	for (int i = 0;i < 169;++i)
	{
		string Mars_num = "";
		f = i % 13;		s = i / 13;
		if (s != 0) Mars_num += sec[s];
		Mars_num += fir[f];
		//注意当i是13的整数倍，0除外，是不用输出个位的0例如tam tret 不用输出个位的0，所以要截取前三个
		if (f == 0 && s) Mars_num = Mars_num.substr(0, 3);
		mp[to_string(i)] = Mars_num;	mp[Mars_num] = to_string(i);//互相映射
	}
}
int main()
{
	Pre_treatment();//反正只有168个先保存答案好了
	int n;
	string num;
	cin >> n;
	getchar();
	while (n--)
	{
		getline(cin, num);
		cout << mp[num] << endl;
	}
	return 0;
}