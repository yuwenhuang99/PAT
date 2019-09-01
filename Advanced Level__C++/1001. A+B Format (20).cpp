#include<cstdio>
#include<string>
using namespace std;
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    string str = to_string(a+b);
    int len = str.length();
    for(int i = 0;i<len;++i)
    {
        printf("%c",str[i]);
        if(str[i]=='-') continue;
        if((len-1-i)%3==0&&i!=len-1) printf(",");
    }
    return 0;
}
