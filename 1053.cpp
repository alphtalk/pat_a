#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 105;
int n, m, s;
struct Node {
	int weight;
	vector<int> child;
}node[MAX];
int path[MAX];
bool cmp(int a, int b) {
	return node[a].weight > node[b].weight;
}
void DFS(int index, int numNode, int sum) {//index表示当前访问的节点
	if (sum > s) {			//大于s就不是这条路径了，直接返回
		return;
	}
	if (sum == s) {			//等于s但不是叶子结点也不对，返回
		if (node[index].child.size() != 0) {
			return;
		}
		for (int i = 0; i < numNode; i++) {
			printf("%d", node[path[i]].weight);
			if (i < numNode - 1) {
				printf(" ");
			}
			else{
				printf("\n");
			}
		}
		return;
	}
	for (int i = 0; i < node[index].child.size(); i++) {
		int child = node[index].child[i];
		path[numNode] = child;
		DFS(child, numNode + 1, sum + node[child].weight);
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &node[i].weight);
	}
	int id, k, child;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &id, &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &child);
			node[id].child.push_back(child);
		}
		sort(node[id].child.begin(), node[id].child.end(), cmp);
	}
	path[0] = 0;
	DFS(0, 1, node[0].weight);
	return 0;
}