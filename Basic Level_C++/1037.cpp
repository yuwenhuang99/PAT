#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int PayGalleon,PaySickle,PayKnut;
	int AGalleon, ASickle, AKnut;
	scanf("%d.%d.%d", &PayGalleon, &PaySickle, &PayKnut);
	int Paysum = PayGalleon * 17 * 29 + PaySickle * 29 + PayKnut;
	scanf("%d.%d.%d", &AGalleon, &ASickle, &AKnut);
	int Asum = AGalleon * 17 * 29 + ASickle * 29 + AKnut;
	if (Asum < Paysum) {
		printf("-");
		swap(Asum, Paysum);
	}
	int difference = Asum - Paysum;
	printf("%d.%d.%d\n", difference / (17 * 29), difference % (17 * 29) / 29, difference % 29);
	return 0;
}