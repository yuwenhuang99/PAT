#include<iostream>
#include<string>
using namespace std;
int main() {
	string str, pw;
	int n;
	cin >> pw >> n;
	getchar();
	bool f = false;
	while (getline(cin, str))
	{
		if (str.length() == 1 && str == "#") break;
		if (f) continue;
		if (str != pw) {
			cout << "Wrong password: " << str << endl;
			if (n == 1) {//这是第三次尝试
				puts("Account locked");
				break;
			}
		}
		else {
			f = true;
			puts("Welcome in");
		}
		n--;
	}
	return 0;
}