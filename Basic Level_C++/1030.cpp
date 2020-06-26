#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n, p;
	int Maxlen = 0;
	cin >> n >> p;
	int* num = new int[n];
	for (int i = 0;i < n;++i) cin >> num[i];
	sort(num, num + n);
	/*M<=P*m => M/p<=m p已知，先找到M，然后就可以确定最大的m,用二分就可以。
	这里用的是lower_bound，为什么不用upper_bound呢，因为可能会有很多重复的元素（也就是有很多个m），这时候返回第一个下标，可以保证最长
	而用upper_bound-1会返回最后一个重复元素的下标，这样长度会变短 
	例如 low_bound的结果是2 2 2 3 4，upper_bound的结果就会使2 3 4.看，他变短了！ 
	*/
	for (int i = n - 1;i >= 0;--i)
	{
		int j = lower_bound(num, num + i, num[i] * 1.0 / p) - num;
		if (i-j+1 > Maxlen) Maxlen = i - j+1;//找到最大的就保存
		if (i + 1 < Maxlen) break;//如果此时的0-i的长度比MaxLen还小，就结束吧，没结果的.
	}
	cout << Maxlen << endl;
	delete[]num;
	return 0;
}