/*
��vector�ڽӱ�洢ͼ��dfs��ȱ���
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
		scanf("%d", &currentPoint);		//Ҫɾ���Ķ�����
		memset(vis, false, sizeof(vis));//ÿ�ζ�����δ������
		int block = 0;					//��ͨ�����
		for (int j = 1; j <= n; j++) {
			if (j != currentPoint && vis[j] == false) {
				dfs(j);
				block++;
			}
		}
		printf("%d\n", block - 1);	//block����ͨ����Ҫblock-1����
	}
	return 0;
}