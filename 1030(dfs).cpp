#include <cstdio>
#include <algorithm>
#include <cstring>   //add
#include <vector>    //add
using namespace std;
const int MAX = 550;
const int INF = 0x3fffffff;
int n, m, st, ed;
int d[MAX], G[MAX][MAX], cost[MAX][MAX];
bool vis[MAX] = { false };
vector<int> pre[MAX];  //alter ，前驱
vector<int> tempPath, path; //add，临时路径，最优路径
int minCost = INF;		//add
void Dijkstra(int s) {
	fill(d, d + MAX, INF);
	//fill(c, c + MAX, INF);			//初始化c数组时，初始化为最大值，因为后面是比较出最小的来
	d[s] = 0;
	//c[s] = 0;
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
					//c[v] = cost[u][v] + c[u];   delete
					pre[v].clear();  //add
					pre[v].push_back(u); //add
				}
				else if (G[u][v] + d[u] == d[v]) {
					//if (cost[u][v] + c[u] < c[v]) {    delete
						//c[v] = cost[u][v] + c[u];
						pre[v].push_back(u); //alter
					//}
				}
			}

		}
	}

}
void DFS(int v) {   //big alter
	if (v == st) {
		tempPath.push_back(v);
		int tempCost = 0;
		for (int i = tempPath.size() - 1; i > 0; i--) {
			int id = tempPath[i], idNext = tempPath[i - 1];
			tempCost += cost[id][idNext];
		}
		if (tempCost < minCost) {
			minCost = tempCost;
			path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++) {
		DFS(pre[v][i]);
	}
	tempPath.pop_back();
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
	DFS(ed);    //alter
	for (int i = path.size() - 1; i >= 0; i--) { //add
		printf("%d ", path[i]);
	}
	printf("%d %d", d[ed], minCost);
	return 0;
}