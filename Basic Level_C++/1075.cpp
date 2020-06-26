#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 1e5 + 5;
int n, k;
struct Node {
	int index, add, data;//加入下标，保证相对顺序不乱
	Node(int ind, int a, int d) : index(ind), add(a), data(d) {}
};
bool cmp(Node a, Node b) {//按要求对链表排序
	if ((a.data ^ b.data) < 0) return a.data < 0;//其中一个是负数
	if ((a.data > k && b.data <= k) || (b.data > k && a.data <= k))	return a.data <= k;//有一个比k大
	return a.index < b.index;//剩下的： 1.都是负数，2.都是大于k的数，3.都在[0,k]的区间内，都按相对次序排序就好了。 
}
int main() {
	int first, addr, data, next, index = 0;
	int Addr[N] = { 0 }, Next[N] = { 0 };
	vector<Node>v;
	scanf("%d%d%d", &first, &n, &k);
	for (int i = 0;i < n;++i) {
		scanf("%d%d%d", &addr, &data, &next);
		Next[addr] = next;
		Addr[addr] = data;
	}
	while (first != -1) {
		v.push_back(Node(index++, first, Addr[first]));
		first = Next[first];
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0;i < index - 1;++i)//不用保存下一个地址，直接从下一个拿地址就好了
		printf("%05d %d %05d\n", v[i].add, v[i].data, v[i + 1].add);
	printf("%05d %d -1\n", v[index - 1].add, v[index - 1].data);
	return 0;
}