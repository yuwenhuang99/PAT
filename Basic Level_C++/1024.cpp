#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
void OutZero(int n)
{
	while (n>0)
	{
		printf("0");
		n--;
	}
}
int main()
{
	char str[10005];
	char num[3][10005];//分别存入整数部分，小数部分，指数部分。其中指数部分带符号，整数部分不带符号
	memset(num, 0, sizeof(num));
	memset(str, 0, sizeof(str));
	const char* d = ".E";//利用了strtok 字符串分割
	char* p;
	char op;
	scanf("%c", &op);
	if (op == '-') cout << op;
	scanf("%s", str);
	p = strtok(str, d);
	int k = 0;
	//分割，然后分别放入num中
	while (p)
	{
		strcpy(num[k++], p);
		p = strtok(NULL, d);
	}
	int exponent = 0;
	sscanf(num[2], "%c%d", &op, &exponent);
	if (exponent == 0) printf("%s.%s\n", num[0], num[1]);
	else {
		if (op == '-')//指数是负的
		{
			printf("0.");
			exponent--;
			OutZero(exponent);
			printf("%s%s\n", num[0], num[1]);
		}
		else {
			printf("%s", num[0]);
			int len = strlen(num[1]);
			for (int i = 0;i < len;++i, --exponent) {
				if (exponent == 0) printf(".");//记住指数没有了，小数还有，要输出小数点
				printf("%c", num[1][i]);
			}
			OutZero(exponent);
		}
	}
	return 0;
}