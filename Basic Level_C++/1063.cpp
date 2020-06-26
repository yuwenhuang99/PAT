#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int n;
	double ans = 0;
	int real, complex;
	cin >> n;
	while (n--)
	{
		cin >> real >> complex;
		double tmp = sqrt(1.0*real * real + complex * complex);
		if (tmp > ans) ans = tmp;
	}
	cout << setprecision(2) << fixed << ans << endl;
	return 0;
}