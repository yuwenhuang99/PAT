#include <iostream>
#include<algorithm>
#include <string>
using namespace std;
int main() { 
	int a, b;
	cin >> a >> b;
	int ans = a * b;
	string str = to_string(ans);
	reverse(str.begin(),str.end());
	cout <<stoi(str) << endl;
	return 0; 
}