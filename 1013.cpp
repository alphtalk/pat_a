/*
用vector邻接表存储图，dfs深度遍历
*/
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int N = 1005;
vector<int> G[N];
bool vis[N];
int currentPoint;
void dfs(int v) {
	if (v == currentPoint)	return;
	vis[v] = true;
	for (int i = 0; i < G[v].size(); i++) {
		if (vis[G[v][i]] == false) {
			dfs(G[v][i]);
		}
	}
}
int n, m, k;
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for (int i = 0; i < k; i++) {
		scanf("%d", &currentPoint);		//要删除的顶点编号
		memset(vis, false, sizeof(vis));//每次都重置未被访问
		int block = 0;					//连通块个数
		for (int j = 1; j <= n; j++) {
			if (j != currentPoint && vis[j] == false) {
				dfs(j);
				block++;
			}
		}
		printf("%d\n", block - 1);	//block块连通块需要block-1条边
	}
	return 0;
}