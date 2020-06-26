#include<iostream>
using namespace std;
int main()
{
    int a, b;
    bool f = false;
    while (cin >> a >> b) {
        if (b != 0) {
            cout << (f?" ":"") << a * b << " " << b - 1;
            f = 1;
        }
    }
    if (!f) cout << "0 0";
    return 0;
}
