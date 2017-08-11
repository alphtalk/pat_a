#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 510;
const int INF = 0x3fffffff;
vector<int> Path, tempPath, pre[MAX];
int Cmax, N, Sp, M;	//ÿ��վ������������,վ����Ŀ���������վ�ı�ţ�·����Ŀ
int num[MAX], minTake = INF, minBack = INF;		//���·������,���ٴ��������г�,���ٴ��ض������г�
int G[MAX][MAX], weight[MAX], d[MAX];
bool vis[MAX] = { false };
void DFS(int v) {
	if (v == 0) {		//Ҷ�ӽ��
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
					take += abs(weight[id]) - back;		//�����Ļ��������Ĳ��ִ����Ĵ�
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
void Dijkstra(int s) {			//����������0-N��N+1�����ĵϽ�˹����
	fill(d, d + MAX, INF);
	d[s] = 0;
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
	fill(G[0], G[0] + MAX*MAX, INF);
	scanf("%d%d%d%d", &Cmax, &N, &Sp, &M);
	for (int i = 1; i <= N; i++) {	//��վ�����г�������������0���ʴ�1��ʼ
		scanf("%d", &weight[i]);	
		weight[i] -= Cmax / 2;		//���������жϲ��仹�Ǵ���
	}
	int t1, t2;
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &t1, &t2);
		scanf("%d", &G[t1][t2]);
		G[t2][t1] = G[t1][t2];
	}
	Dijkstra(0);
	DFS(Sp);			//�ӳ������վ�����������·��
	printf("%d ", minTake);
	for (int i = Path.size()-1; i >= 0; i--) {
		printf("%d", Path[i]);
		if (i > 0)	printf("->");
	}
	printf(" %d", minBack);
	
	return 0;
}