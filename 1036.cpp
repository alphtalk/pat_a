/*
����汾ͨ���������һ�����������δ��󣬸���ˢ�µİ취
#include<cstdio>
#include<algorithm>
using namespace std;
struct Student {
	char name[11];
	char gender;
	char ID[11];
	int grade;
}s[100];
bool cmp(Student a, Student b) {
	if (a.gender == 'M' && b.gender == 'M') { //���ԴӸߵ�������ʹ��͵��������
		return a.grade > b.grade;
	}
	if (a.gender == 'F' && b.gender == 'F') { //Ů�ԴӸߵ�������ʹ��ߵ����ڵ�һ
		return a.grade > b.grade;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i].name);
		getchar();
		scanf("%c", &s[i].gender);
		scanf("%s", s[i].ID);
		scanf("%d", &s[i].grade);
	}
	sort(s, s + n, cmp);
	bool have_M = false;				//����
	bool have_F = false;				//��Ů
	for (int i = 0; i < n; i++) {
		if (s[i].gender == 'M')
			have_M = true;
		if (s[i].gender == 'F')
			have_F = true;
	}
	int count = 0;
	if(have_F)	printf("%s %s\n", s[0].name, s[0].ID);
	else {
		printf("Absent\n");
		count++;
	}
	if (have_M)	printf("%s %s\n", s[n-1].name, s[n-1].ID);
	else {
		printf("Absent\n");
		count++;
	}
	if (count > 0)	printf("NA");
	else	printf("%d", s[0].grade - s[n - 1].grade);
	return 0;
}
*/

/*
�Ż�
*/
#include<cstdio>
#include<algorithm>
using namespace std;
struct Student {
	char name[11];
	char gender;
	char ID[11];
	int grade;
}M, F, temp;
int main() {
	int n;
	M.grade = 101;
	F.grade = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %c %s %d", temp.name, &temp.gender, temp.ID, &temp.grade);
		if (temp.gender == 'M' && temp.grade < M.grade) {
			M = temp;
		}
		if (temp.gender == 'F' && temp.grade > F.grade) {
			F = temp;
		}
	}
	if (F.grade == -1)	printf("Absent\n");
	else 	printf("%s %s\n", F.name, F.ID);
	if (M.grade == 101)	printf("Absent\n");
	else 	printf("%s %s\n", M.name, M.ID);
	if (F.grade==-1 || M.grade==101)	printf("NA");
	else	printf("%d", F.grade-M.grade);
	return 0;
}