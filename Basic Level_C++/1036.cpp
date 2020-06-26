#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,r=0;
    char c;
    scanf("%d %c",&n,&c);
    r = (n&1)?n/2+1:n/2;
    for(int i = 1;i<=n;++i) cout<<c;
    cout<<endl;
    for(int i = 1;i<r-1;++i)
    {
        cout<<c;
        for(int j = 1;j<n-1;++j) cout<<" ";
        cout<<c<<endl;
    }
    for(int i = 1;i<=n;++i) cout<<c;
    cout<<endl;
    return 0;
}
