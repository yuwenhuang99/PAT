#include<iostream>
using namespace std;
int main() {
    int n, count = 0;
    cin >> n;
    while (n != 1) {
        (n & 1) ? n = (3 * n + 1) / 2 : n /= 2;
        count++;
    }
    cout << count << endl;
    return 0;
}
