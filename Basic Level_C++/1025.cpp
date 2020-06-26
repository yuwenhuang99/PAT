/*憨憨代码来了！！！
 这题搞了一下午，干。自己水平简直在海平面以下
 聊聊我写的思路吧。我开了一个1e5的数组，直接把他当做“内存”。
 然后每个地址放的就是这个节点，包括：数据以及下一个节点的地址
 然后就是翻转，每次翻转我都看成是一个链表的翻转，而不是一部分，
 这样搞的就很复杂了，我先保存第一个结点的地址FirstAddress。
 然后呢，每次翻转都记录翻转链表的尾部，之后让尾部结点的next指向下一次的头结点
 画个图体会一下 例如 1->2->3->4->5->6 k=3，初始尾部是-1,翻转一次后尾部是1，然后让1指向下一次的头就是6
*/
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
const int N = 1e5;
typedef struct Node {
	int data;
	int next;
};
Node Address[N];
int FirstAddress = -1, TailAddress = -1;
bool f = 1;
int Reverse(int pos, int k)
{
	int p = -1, q = -1;
	int FirstPos = pos;
	//链表翻转
	while (k--)
	{
		q = Address[pos].next;
		Address[pos].next = p;
		p = pos;
		pos = q;
	}
	/*因为翻转后第一个结点变成最后一个结点，最后一个结点变成第一个，所以要让第一个结点指向最后一个结点的next
	这样链才不会断*/
	Address[FirstPos].next = pos;
	if(TailAddress!=-1)
	Address[TailAddress].next = p;
	if (f) {//第一次翻转的头是真的头！！
		FirstAddress = p;
		f = 0;
	}
	return TailAddress = FirstPos; //返回翻转链表的最后一个元素
}
void OutPut(int FirstAddress)//输出，没啥好说的。
{
	while (FirstAddress != -1)
	{
		cout << setw(5) << setfill('0') << FirstAddress << " " << Address[FirstAddress].data << " ";
		if (Address[FirstAddress].next == -1)
			cout << "-1" << endl;
		else cout << setw(5) << setfill('0') << Address[FirstAddress].next << endl;
		FirstAddress = Address[FirstAddress].next;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	int n, k;
	int add, data, next;
	cin >> FirstAddress >> n >> k;
	for (int i = 0;i < n;++i)
	{
		cin >> add >> data >> next;
		if (add == -1) continue;
		Address[add].data = data;
		Address[add].next = next;
	}//存入地址中，方便取出
	int p = -1, pos  = FirstAddress;
	int FIR = pos,sum=0;
	/*这里好坑，开始测试点6一直过不去。后面搜csdn才明白，原来有些结点不在链表上！干。
	所以这里先记录一下实际上一共有多少个结点*/
	while (FIR!=-1)
	{
		sum++;
		FIR = Address[FIR].next;
	}
	//要用实际结点哦，别用n
	while (sum - k >= 0)
	{
		p = Reverse(pos, k);//k位k位一翻转，然后下一次翻转的起点就是尾巴的下一个结点
		pos = Address[p].next;
		sum -= k;
	}
	OutPut(FirstAddress);
	return 0;
}