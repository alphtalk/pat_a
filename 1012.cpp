#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
struct Student {
	int ID, grade[4];
}s[2005];
int n, m, c;
char course[4] = { 'A','C','M','E' };
const int MAX = 1000000;
int Rank[4][MAX];

bool cmp(Student s1, Student s2) {
	return  s1.grade[c] > s2.grade[c];
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0;  i < n; i++) {
		scanf("%d%d%d%d", &s[i].ID, &s[i].grade[1], &s[i].grade[2], &s[i].grade[3]);
		s[i].grade[0] = (int)round(1.0*(s[i].grade[1] + s[i].grade[2] + s[i].grade[3]) / 3);
	}
	
	for (c = 0; c < 4; c++) {
		sort(s, s + n, cmp);
		Rank[c][s[0].ID] = 1;
		for (int i = 1; i < n; i++) {		//排序的逻辑
			if (s[i].grade[c] == s[i - 1].grade[c]) {
				Rank[c][s[i].ID] = Rank[c][s[i - 1].ID];
			}
			else {
				Rank[c][s[i].ID] = i + 1;
			}
		}
	}
	int check_id;
	for (int i = 0; i < m; i++) {
		scanf("%d", &check_id);
		if (Rank[0][check_id] == 0)		printf("N/A\n");
		else {
			int k = 0;
			for (int j = 0; j < 4; j++) {		//找出四门课程中排名最靠前的
				if (Rank[j][check_id] < Rank[k][check_id]) {
					k = j;
				}
			}
			printf("%d %c\n", Rank[k][check_id], course[k]);
		}
	}
	return 0;
}