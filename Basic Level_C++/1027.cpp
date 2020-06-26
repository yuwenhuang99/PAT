#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//所需字符为2*n*n-1,n为行数。1，3，5这就是3行，5是2*3-1
int needSum[40];
void NeedSum();//求得在i行下所需字符总数的量，存入数组
void Outchar(int row, int i, char c);//打印一行沙漏，包括空格与字符
int main()
{
	NeedSum();
	int n;
	char c;
	cin >> n >> c;
	int row = upper_bound(needSum, needSum + 30, n) - needSum - 1;//要减1哦，因为要找小的
	//上半部，包括中间
	for (int i = row;i >= 1;--i)
		Outchar(row, i, c);
	//下半部
	for (int i = 2;i <= row;++i)
		Outchar(row, i, c);
	cout << n - needSum[row] << endl;
	return 0;
}
void NeedSum()
{
	/*最好把比n=1000时的行数大的也求出来，不然upper_bound()会返回30，因为找不到
	 2020年嘛，那就2020好了*/
	for (int i = 1;2 * i * i - 1 <= 2020;++i)
		needSum[i] = 2 * i * i - 1;
}
void Outchar(int row, int i, char c)
{
	for (int j = 0;j < row - i;++j) cout << " ";
	for (int k = 0;k < 2 * i - 1;++k) cout << c;
	cout << endl;
}