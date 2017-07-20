/*
很简单一遍过结构体排序，输出给定两个数字中间的即可
*/
#include<cstdio>
#include<algorithm>
using namespace std;
struct Student {
	char name[11];
	char ID[11];
	int grade;
}s[100];
bool cmp(Student a, Student b) {
	return a.grade > b.grade;
}
int main() {
	int n, grade1, grade2;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s%s%d", s[i].name, s[i].ID, &s[i].grade);
	}
	scanf("%d%d", &grade1, &grade2);
	sort(s, s + n, cmp);
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (s[i].grade >= grade1 && s[i].grade <= grade2) {
			printf("%s %s\n", s[i].name, s[i].ID);
			count++;
		}
	}
	if (count == 0)	printf("NONE");

}