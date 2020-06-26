#include<iostream>
#include<algorithm>
using namespace std;
int a[100], b[100], n;
int index;
bool Is_insert() {
	int i;
	for (i = 1;i < n && b[i] >= b[i - 1];++i);//注意要>=，不然样例四会浮点数错误
	index = i;
	for (int j = i;j < n;++j)
		if (a[j] != b[j]) return false;
	return true;
}
void OutPut() {
	for (int i = 0;i < n;++i) cout << (i ? " " : "") << a[i];
}
void Insert() {
	cout << "Insertion Sort" << endl;
	sort(a, a + index + 1);
	OutPut();
}
bool Judge() {
	for (int i = 0;i < n;++i)
		if (a[i] != b[i]) return true;
	return false;
}
void Merge() {
	cout << "Merge Sort" << endl;
	int len = 1;//子序列长度
	bool f = true;
	while (f) {
		if (!Judge()) f = false;
		len <<= 1;
		for (int i = 0;i < n / len;++i)
			sort(a + i * len, a + (i + 1) * len);
		if (n % len)
			sort(a + n / len * len, a + n);
	}
	OutPut();
}
int main() {
	cin >> n;
	for (int i = 0;i < n;++i) cin >> a[i];
	for (int i = 0;i < n;++i) cin >> b[i];
	if (Is_insert()) Insert();
	else Merge();
	return 0;
}