/* hello！！这道题呢，主要思路就是分情况讨论，然后讨论着讨论着就变成了100行
建议：真的不到万不得已千万别看这个代码，我真的，写完自己都不想再看一眼

我尽量说出我的思路，然后你自己写代码，肯定比我的简单，因为我真的不想再改了。。。嘻嘻
思路：用结构体保存准考证号和分数，这是基操。题目讲得也很详细。
有两种做法:1.啥都不管，询问一次按照条件遍历一次。2.多弄几个vector按题目要求分别存储。用空间换时间
第一种方法你肯定没问题，我脑抽，用得第二种，太多额外空间了。
举个例子，对于情况一，可以用三个vector保存A,T,B三个级别的考生，然后询问的时候直接从这里拿就好了
再例如情况二，你开个1000的数组，下标就是考场编号，然后用结构体记录人数和总成绩，询问也直接拿就好了
至于第三种，我想同情况二结合起来，但没有想到什么好办法，所以只能遍历一遍了

*/
#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
#include <cstring>
using namespace std;
//写着写着搞出三个结构体，好家伙，不用慌这个，知道存什么，以及为了方便排序和存储就行
typedef struct StuInfo {
	string id;
	int score;
	StuInfo() {}
	StuInfo(string _id, int _score) : id(_id), score(_score) {}
};
struct Type2 {
	int cnt, score;
	Type2() { cnt = score = 0; }
};
struct Type3 {
/*为啥要这个呢，咱们把数组下标作为考场编号，那排完序，
人数与考场编号不就不对应了吗，所以要保存一下考场编号*/
	int index, cnt;
	Type3() { index = cnt = 0; }
	Type3(int a, int b) :index(a), cnt(b) {}
};
bool cmp(StuInfo a, StuInfo b) {//情况1的排序
	return  (a.score == b.score) ? (a.id < b.id) : (a.score > b.score);
}
bool cmp3(Type3 a, Type3 b) {//情况3
	return (a.cnt == b.cnt) ? (a.index < b.index) : (a.cnt > b.cnt);
}
void OutputType1(vector<StuInfo> s) {//输出情况一
	for (auto i : s) printf("%s %d\n", i.id.c_str(), i.score);
	if (s.empty()) puts("NA");
}
int main() {
	int n, m;
	string _id;
	_id.resize(100);//你要用scanf输入string 可以用这种方式，先给string分配空间
	int _score, type;
	int index, cnt = 0;//考场编号,人数
	string date;//日期
	scanf("%d%d", &n, &m);
	vector<StuInfo> B, A, T;//按级别存放
	vector<Type2> v(1000);//按考场编号存放
	StuInfo* stu = new StuInfo[n + 5];
	for (int i = 0;i < n;++i) {
		getchar();
		scanf("%s%d", &_id[0], &_score);
		stu[i] = StuInfo(_id, _score);
		//情况1
		if (_id[0] == 'T') T.push_back(StuInfo(_id, _score));
		else if (_id[0] == 'A') A.push_back(StuInfo(_id, _score));
		else B.push_back(StuInfo(_id, _score));
		//情况2
		index = (_id[1] - '0') * 100 + (_id[2] - '0') * 10 + (_id[3] - '0');
		v[index].cnt++;v[index].score += _score;
	}
	sort(A.begin(), A.end(), cmp);sort(T.begin(), T.end(), cmp);sort(B.begin(), B.end(), cmp);
	string str;str.resize(100);
	for (int i = 1;i <= m;++i) {
		getchar();
		scanf("%d%s", &type, &str[0]);
		printf("Case %d: %d %s\n", i, type, str.c_str());
		if (type == 1) {
			if (str[0] == 'T') OutputType1(T);
			else if (str[0] == 'A') OutputType1(A);
			else OutputType1(B);
		}
		else if (type == 2) {
			if (v[atoi(str.c_str())].cnt == 0) puts("NA");
			else printf("%d %d\n", v[atoi(str.c_str())].cnt, v[atoi(str.c_str())].score);
		}
		else {//第三种情况，暂时没想到更好的，只好遍历一遍了，然后再保存答案，排序，输出
			bool f = true;
			vector<Type3> v3(1000);
			for (int i = 0;i < n;++i) {
				if (strcmp((stu[i].id).substr(4, 6).c_str(), str.c_str()) == 0) {
					int j = atoi((stu[i].id).substr(1, 3).c_str());
					f = false;
					v3[j].cnt++; v3[j].index = j;
				}
			}
			if (f) puts("NA");
			else {
				sort(v3.begin(), v3.end(), cmp3);
				for (auto i = 0;i < 1000;++i)
					if (v3[i].cnt) printf("%d %d\n", v3[i].index, v3[i].cnt);
			}
		}
	}
	return 0;
}