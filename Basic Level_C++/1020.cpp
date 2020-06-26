#include<iostream>
#include<algorithm>
#include<cstring>
#include<iomanip>
using namespace std;
typedef struct MoonCakes {//不用double有个样例过不去，可题目是说n个正数啊，不理解
	double quantity;
	double value;
};
bool cmp(MoonCakes a, MoonCakes b) { return a.value * b.quantity > b.value * a.quantity; }
int main()
{
	int n, d;
	cin >> n >> d;
	MoonCakes* MoonCake = new MoonCakes[n];
	for (int i = 0;i < n;++i) cin >> MoonCake[i].quantity;
	for (int i = 0;i < n;++i) cin >> MoonCake[i].value;
	sort(MoonCake, MoonCake + n, cmp);
	double profit = 0;
	for (int i = 0;i < n;++i)
	{
		if (MoonCake[i].quantity <= d) {
			profit += MoonCake[i].value;
			d -= MoonCake[i].quantity;
		}
		else {
			profit += d * (MoonCake[i].value *1.0/ MoonCake[i].quantity);
			break;
		}
	}
	cout << fixed << setprecision(2) << profit << endl;
	delete[]MoonCake;
	return 0;
}