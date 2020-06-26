#include<iostream>
#include<cstring>
using namespace std;
int main() {
    string pinyin[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
    string str;
    cin >> str;
    int sum = 0;
    int len = str.length();
    for (int i = 0;i < len;++i) {
        sum += str[i] - '0';
    }
    int n[1005], i = 0;
    while (sum != 0) {
        n[i++] = sum % 10;
        sum /= 10;
    }
    for (int j = i - 1;j >= 0;--j) {
        cout << pinyin[n[j]];
        if (j != 0) cout << " ";
    }
    cout << endl;
    return 0;
}
