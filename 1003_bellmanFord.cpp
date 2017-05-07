#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
const int INF = 0x3fffffff;
const int MAXV = 550;
int n, m, st, ed;
int weight[MAXV];
struct Node {//邻接表实现，要创建节点
	int v, dis;  //临接点和临接边
	Node(int _v, int _dis) : v(_v), dis(_dis) {}//构造函数，方便赋值
};
int d[MAXV], w[MAXV], num[MAXV];//最短距离，最大点权之和，最短路径条数
vector<Node> Adj[MAXV];  //邻接表
set<int> pre[MAXV];
void Bellman(int s) {
	//初始化
	fill(d, d + MAXV, INF);
	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;
	//求解数组d
	for (int i = 0; i < n - 1; i++) {
		for (int u = 0; u < n; u++) {
			for (int j = 0; j < Adj[u].size(); j++) {
				int v = Adj[u][j].v;  //邻接边的顶点
				int dis = Adj[u][j].dis;	//邻接边的边权
				if (d[u] + dis < d[v]) {
					d[v] = d[u] + dis;
					w[v] = w[u] + weight[v];
					num[v] = num[u];
					pre[v].clear();
					pre[v].insert(u);
				}
				else if (d[u] + dis == d[v]) {
					if (w[u] + weight[v] > w[v]) { //务必搞清楚是大于还是小于
						w[v] = w[u] + weight[v];
					}
					pre[v].insert(u);
					num[v] = 0;
					set<int>::iterator it;
					for (it = pre[v].begin(); it != pre[v].end(); it++) {
						num[v] += num[*it];
					}
				}
			}
		}
	}
}
int main() {
	scanf("%d%d%d%d", &n, &m, &st, &ed);
	for (int i = 0; i < n; i++) {
		scanf("%d", &weight[i]);
	}
	int u, v, wt;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &u, &v, &wt);
		Adj[u].push_back(Node(v, wt));
		Adj[v].push_back(Node(u, wt));
	}
	Bellman(st);
	printf("%d %d", num[ed], w[ed]);
	return 0;
}