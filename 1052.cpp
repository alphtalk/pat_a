#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100005;
struct Node {
	int data, next, address;	//��Ϊ���Ҫ���address,�������1032������һ��address
	bool flag;
}node[MAX];
bool cmp(Node a, Node b) {
	if (a.flag == false || b.flag == false) {
		return a.flag > b.flag;
	}
	else {
		return a.data < b.data;
	}
}
int main() {
	int N, address_st;
	scanf("%d%d", &N, &address_st);
	for (int i = 0; i < N; i++) {
		node[i].flag = false;
	}
	int a, next, data;
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d", &a, &data, &next);
		node[a].data = data;
		node[a].next = next;
		node[a].address = a;
	}
	int count = 0, p = address_st;
	while (p != -1) {
		node[p].flag = true;
		count++;
		p = node[p].next;
	}
	if (count == 0) {
		printf("0 -1");
	}
	else {
		sort(node, node + MAX, cmp);
		printf("%d %05d\n", count, node[0].address);
		for (int i = 0; i < count; i++) {
			if (i != count - 1) {	
			//��Ϊ��ʱֻ�ǶԽڵ��data�����򣬽ڵ��next��û���޸ģ����Ե����������i+1���ڵ��adressֵ
				printf("%05d %d %05d\n", node[i].address, node[i].data, node[i+1].address);
			}
			else {
				printf("%05d %d -1\n", node[i].address, node[i].data);
			}
		}
	}
	
	return 0;
}