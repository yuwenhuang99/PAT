#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a = n / 100;
    int b = (n % 100) / 10;
    int c = (n % 10);
    while (a--) cout << "B";
    while (b--) cout << "S";
    for (int i = 1;i <= c;++i) cout << i;
    cout << endl;
    return 0;
}
