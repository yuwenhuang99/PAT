#include <iostream>
using namespace std;
int main() {
	int count[4] = { 0 };
	string emoji[5][20];
	int c, left_hand, right_hand, mouth, left_eye, right_eye, k;
	for (int i = 1; i <= 3; ++i) {
		string s = "";
		int cnt = 1;
		while ((c = getchar()) != '\n') {//一次读取一行
			if (c != '[') continue;//没有遇到[一直getchar
			while ((c = getchar()) != ']') {//碰到了，进入新的世界，
				if (c != ' ');//空格不管
				s += c;
			}
			emoji[i][cnt++] = s;//加入表情包
			s = "";
		}
		count[i] = cnt;
	}
	cin >> k;
	while (k--) {//变量名太复杂了，不用管，记得判断数据不合法的两种情况，大于总个数，以及小于1
		cin >> left_hand >> left_eye >> mouth >> right_eye >> right_hand;
		if (left_hand >= count[1] || left_eye >= count[2] | mouth >= count[3]
			|| right_eye >= count[2] || right_hand >= count[1]
			|| left_hand < 1 || left_eye < 1 || mouth < 1 || right_eye < 1 || right_hand < 1
			//注意，可能会小于1
			) {
			puts("Are you kidding me? @\\/@");//记得转义
		}
		else
			cout << emoji[1][left_hand] << '(' << emoji[2][left_eye]
			<< emoji[3][mouth]
			<< emoji[2][right_eye] << ')' << emoji[1][right_hand] << endl;
	}
	return 0;
}