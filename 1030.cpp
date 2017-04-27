#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 550;
const int INF = 0x3fffffff;
int n, m, st, ed;
int d[MAX], G[MAX][MAX], cost[MAX][MAX], c[MAX], pre[MAX];
bool vis[MAX] = { false };
void Dijkstra(int s) {
	fill(d, d + MAX, INF);
	fill(c, c + MAX, INF);			//初始化c数组时，初始化为最大值，因为后面是比较出最小的来
	d[s] = 0;
	c[s] = 0;
	for (int i = 0; i < n; i++) {		//这里是固定的循环n次，与下一个构成双层for循环
		int u = -1, min = INF;
		for (int j = 0; j < n; j++) {
			if (d[j] < min && vis[j] == false) {   //两个==号，注意注意
				u = j;
				min = d[j];
			}
		}
		if (u == -1) return;
		vis[u] = true;		//标记为访问过
		for (int v = 0; v < n; v++) {
			if (G[u][v] != INF && vis[v] == false) { //G[u][v]!=INF这个条件不要忘了，两个等号~~
				if (G[u][v] + d[u] < d[v]) {
					d[v] = G[u][v] + d[u];
					c[v] = cost[u][v] + c[u];
					pre[v] = u;
				}
				else if (G[u][v] + d[u] == d[v]) {
					if (cost[u][v] + c[u] < c[v]) {
						c[v] = cost[u][v] + c[u];
						pre[v] = u;
					}
				}
			}

		}
	}

}
void DFS(int s, int v) {
	if (s == v) {
		printf("%d", v);
		return;
	}
	DFS(s, pre[v]);
	printf(" %d", v);
}
int main() {
	scanf("%d%d%d%d", &n, &m, &st, &ed);
	fill(G[0], G[0] + MAX*MAX, INF);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		scanf("%d%d", &G[u][v], &cost[u][v]);
		G[v][u] = G[u][v];
		cost[v][u] = cost[u][v];
	}
	Dijkstra(st);
	DFS(st,ed);
	printf(" %d %d",d[ed],c[ed]);
	return 0;
}