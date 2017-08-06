#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 510;
const int INF = 0x3fffffff;
vector<int> Path, tempPath, pre[MAX];
int Cmax, N, Sp, M;	//每个站的最大承载能力,站的数目，出问题的站的标号，路的数目
int num[MAX], minTake = INF, minBack = INF;		//最短路径条数,最少带多少自行车,最少带回多少自行车
int G[MAX][MAX], weight[MAX], d[MAX];
bool vis[MAX] = { false };
void DFS(int v) {
	if (v == 0) {		//叶子结点
		tempPath.push_back(v);
		int take = 0, back = 0;
		for (int i = tempPath.size() - 1; i >= 0; i--) {
			int id = tempPath[i];
			if (weight[id] > 0)
				back += weight[id];
			else {
				if (back > abs(weight[id])) {
					back -= abs(weight[id]);
				}
				else {
					take += abs(weight[id]) - back;		//不够的话，不够的部分从中心带
					back = 0;
				}
			}
		}
		if (take < minTake) {
			minTake = take;
			minBack = back;
			Path = tempPath;
			
		}
		else if (take == minTake&&back < minBack) {
			minBack = back;
			Path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++){
		DFS(pre[v][i]);
	}
	tempPath.pop_back();
}
void Dijkstra(int s) {			//别忘了这是0-N共N+1个结点的迪杰斯特拉
	for (int i = 0; i <= N; i++) {
		int u = -1, min = INF;
		for (int j = 0; j <= N; j++) {
			if (vis[j] == false && d[j] < min) {
				u = j;
				min = d[j];
			}
		}
		if (u == -1)	return;
		vis[u] = true;
		for (int v = 0; v <= N; v++) {		
			if (vis[v] == false&&G[u][v]!=INF) {
				if (d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (d[u] + G[u][v] == d[v])
					pre[v].push_back(u);
			}
		}
		
	}
}
int main() {
	fill(d, d + MAX, INF);
	d[s] = 0;
	fill(G[0], G[0] + MAX*MAX, INF);
	scanf("%d%d%d%d", &Cmax, &N, &Sp, &M);
	for (int i = 1; i <= N; i++) {	//各站的自行车数不包括中心0，故从1开始
		scanf("%d", &weight[i]);	
		weight[i] -= Cmax / 2;		//根据正负判断补充还是带走
	}
	int t1, t2;
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &t1, &t2);
		scanf("%d", &G[t1][t2]);
		G[t2][t1] = G[t1][t2];
	}
	Dijkstra(0);
	DFS(Sp);			//从出问题的站往回深度搜索路径
	printf("%d ", minTake);
	for (int i = Path.size()-1; i >= 0; i--) {
		printf("%d", Path[i]);
		if (i > 0)	printf("->");
	}
	printf(" %d", minBack);
	
	return 0;
}