#include<cstdio>
/*1.先对输入的两个有理数进行化简，分子为0输出0，分母为1输出整数
  2.计算，并化成带分数的形式
  注意：
  1.有理数、带分数为负数要加括号
  2.要用long long，不然会浮点数错误	也就是溢出，开始以为是除0错误，结果判断半天，改成long long后，ac了 黑人问号？？
  3.这题有很多细节要注意。见注释
  */
typedef long long ll;
ll gcd(ll a, ll b)
{
	return !b ? a : gcd(b, a % b);
}
typedef struct RationalNum {//这里我用结构体存储一个有理数
	ll a, b, k;
	RationalNum() : k(0) {}
} Rnum;
ll f = 1;//判断有理数是否是负数 f=-1则是负数
void Simplify(Rnum& num);//简化一个有理数
void Outone(Rnum num);//输出一个有理数
void OutAll(Rnum  n1, Rnum n2, Rnum n3, char c);//输出一个等式
void Calculate(Rnum n1, Rnum n2);//四则运算
int main()
{
	//freopen("in.txt", "r", stdin);
	Rnum n1, n2;
	scanf("%lld/%lld%lld/%lld", &n1.a, &n1.b, &n2.a, &n2.b);
	Calculate(n1, n2);
	return 0;
}
void Simplify(Rnum& num)
{
	f = 1;
	if (num.b < 0)
	{//虽然输入的时候保证负号在分子前，但你计算得到的n3，可不会自动挪负号，所以还是要判断一下
		num.a = -num.a;
		num.b = -num.b;
	}
	if (num.a < 0) {
		num.a = -num.a;
		f = -f;//表明是负数
	}
	ll x = gcd(num.a, num.b);
	num.a /= x;
	num.b /= x;
	if (num.a >= num.b) {
		num.k = f * (num.a / num.b); //哪怕f=-1，当该数是真分数,k也会是0.那么负号就被省去了这我当时一直错的地方
		num.a %= num.b;
	}
}
void Outone(Rnum num)
{//输出一个时先简化，再输出.输出还是要考虑一些东西的，可以自己模拟一下
	Simplify(num);
	if (num.k < 0) printf("(");
	if (num.k) printf("%lld", num.k);
	/*注意一下这个情况，可能例如 -1/3的情况，被化简后=>k=0,f=-1,a=1,b=3，那么如果不特判，会输出1/3
	所以要特判真分数是负的情况*/
	else if (num.k == 0 && f == -1) printf("(-");
	if (num.a == 0) {//a=0,不用再管b是什么了
		if (num.k == 0) printf("0");// 不然,k输出了，a这个0就不用再输出了
	}
	else {
		if (num.k) printf(" ");
		printf("%lld", num.a);
		if (num.b != 1) printf("/%lld", num.b);
	}
	if (num.k < 0 || (num.k == 0 && f == -1)) printf(")");//同理要特判真分数是负的
}
void OutAll(Rnum  n1, Rnum n2, Rnum n3, char c) {//输出一个等式
	Outone(n1);
	printf(" %c ", c);
	Outone(n2);
	printf(" = ");
	if (c == '/' && n3.b == 0) printf("Inf");//分母为0特判
	else Outone(n3);
	printf("\n");
}
void Calculate(Rnum n1, Rnum n2) {//这就没什么了，四则运算的分子分母你肯定会算的
	Rnum n3;
	//加法
	n3.a = n1.a * n2.b + n2.a * n1.b;n3.b = n1.b * n2.b;OutAll(n1, n2, n3, '+');
	//减法
	n3.a = n1.a * n2.b - n2.a * n1.b;OutAll(n1, n2, n3, '-');
	//乘法
	n3.a = n1.a * n2.a;n3.b = n1.b * n2.b;OutAll(n1, n2, n3, '*');
	//除法
	n3.a = n1.a * n2.b;n3.b = n1.b * n2.a;OutAll(n1, n2, n3, '/');
}