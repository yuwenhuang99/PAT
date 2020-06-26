#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n;
	int Min = 0x7f7f7f7f, ans1 = 0;
	int Max = 0,ans2=0;
	int id, x, y;
	cin >> n;
	while (n--)
	{
		cin >> id >> x >> y;
		int dis = x * x + y * y;
		if (dis > Max) {
			Max = dis;
			ans2 = id;
		}
		else if (dis < Min) {
			Min = dis;
			ans1 = id;
		}
	}
	cout <<setw(4)<<setfill('0')<< ans1 << " " <<setw(4)<<setfill('0')<< ans2<<endl;
	return 0;
}