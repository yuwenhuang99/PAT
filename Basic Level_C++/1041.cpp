#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
typedef struct Info {
	string str;
	int id;
	Info(string s,int _id) : str(s),id(_id) {}
	Info(){}
};
Info StuInfo[1005];
int main()
{
	int n;
	string str;
	int TestId, ExamId;
	cin >> n;
	while (n--)
	{
		cin >> str >> TestId >> ExamId;
		StuInfo[TestId] = Info(str, ExamId);
	}
	cin >> n;
	while (n--)
	{
		cin >> TestId;
		cout << StuInfo[TestId].str << " " << StuInfo[TestId].id << endl;
	}
	return 0;
}