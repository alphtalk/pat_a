/*
先将所有节点保存到结构数组中，再分别遍历两条路径比较。
*/
#include <cstdio>
const int MAX = 100005;
struct Node {
	char data;
	int address;
	bool flag;
}node[MAX];
int main() {
	for (int i = 0; i < MAX; i++) {
		node[i].flag = false;
	}
	int a1, a2, N;
	char c;
	scanf("%d %d %d", &a1, &a2, &N);
	int temp, next;
	for (int i = 0; i < N; i++) {
		scanf("%d %c %d", &temp, &c, &next);
		node[temp].data = c;
		node[temp].address = next;
	}
	int p;
	for (p = a1; p != -1; p = node[p].address) {
		node[p].flag = true;
	}
	for (p = a2; p != -1; p = node[p].address) {
		if (node[p].flag == true) {
			break;
		}
	}
	if (p != -1) {
		printf("%05d\n",p);
	}
	else {
		printf("-1\n");
	}
	return 0;
}