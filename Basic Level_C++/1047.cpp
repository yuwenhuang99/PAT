#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int team[1005];
	memset(team, 0, sizeof(team));
	int n;
	int Max = 0;
	scanf("%d", &n);
	int TeamId, PlayerId, grade;
	while (n--)
	{
		scanf("%d-%d%d", &TeamId, &PlayerId, &grade);
		team[TeamId] += grade;
		if (team[TeamId] > team[Max]) Max = TeamId;
	}
	printf("%d %d\n", Max, team[Max]);
	return 0;
}