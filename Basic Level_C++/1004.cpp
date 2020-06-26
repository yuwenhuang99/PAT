#include<iostream>
#include<cstring>
using namespace std;
class Stu {
public:
	char name[20];
	char id[20];
	int grade;
	Stu(int x = 0) : name(),id(),grade(x) {}
	Stu(char* _name, char* _id, int _grade) {
		strcpy(name, _name);
		strcpy(id, _id);
		grade = _grade;
	}
	void Print();
};
void Stu::Print() {
	cout << name << " " << id << endl;
}
int main()
{
	ios::sync_with_stdio(false);
	Stu Max, Min(100);
	int n;
	int grade = 0;
	cin >> n;
	while (n--)
	{
		char name[20], id[20];
		cin >> name >> id >> grade;
		if (grade > Max.grade)
			Max = Stu(name, id, grade);
		if (grade < Min.grade)
			Min = Stu(name, id, grade);
	}
	Max.Print();
	Min.Print();
	return 0;
}