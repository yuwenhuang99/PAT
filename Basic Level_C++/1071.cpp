#include<iostream>
using namespace std;
int main() {
	int sum, k;
	int n1, b, t, n2;
	cin >> sum >> k;
	while (k--)
	{
		cin >> n1 >> b >> t >> n2;
		if (t > sum) 
			cout << "Not enough tokens.  Total = " << sum << "." << endl;
		else {
			if ((n2 > n1 && b == 1) || (n2 < n1 && b == 0)) {
				sum += t;
				cout << "Win "<<t<<"!  Total = "<<sum<<"."<<endl;
			}
			else {
				sum -= t;
				cout << "Lose " << t << ".  Total = " << sum << "." << endl;
			}
		}
		if (sum == 0) {
			cout << "Game Over." << endl;
			break;
		}
	}
	return 0;
}