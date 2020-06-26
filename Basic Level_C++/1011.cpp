#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    long a, b, c;
    cin >> t;
    for (int i = 1;i <= t;++i)
    {
        cin >> a >> b >> c;
        cout << "Case #" << i << ": ";
        cout << ((a + b > c) ? "true" : "false") << endl;
    }
    return 0;
}
