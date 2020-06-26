#include<cstdio>
#include<cstring>
using namespace std;
int main() {
	int n, m, a, b, val;
	int matrix[605][605];
	scanf("%d%d%d%d%d", &m, &n, &a, &b, &val);
	for (int i = 0;i < m;++i)
		for (int j = 0;j < n;++j)
			scanf("%d", &matrix[i][j]);

	for (int i = 0;i < m;++i) {
		for (int j = 0;j < n;++j) {
			if (j) printf(" ");
			if (matrix[i][j] >= a && matrix[i][j] <= b) printf("%03d",val);
			else printf("%03d", matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}