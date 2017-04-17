#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXV = 510;		//��󶨵��� 
const int INF = 0x3fffffff;	//�����
//nΪ��������mΪ������st��ed�ֱ�Ϊ�����յ�
//GΪ�ڽӾ���洢��Ȩ��weightΪ��Ȩ��d[]��¼��̾��룬w[]��¼����Ȩ֮�ͣ�num[]��¼���·������
int n, m, st, ed, G[MAXV][MAXV], weight[MAXV], d[MAXV], w[MAXV], num[MAXV];
bool vis[MAXV] = { false };		//vis[i]==true��ʾ����i�ѷ��ʣ���ʼ����Ϊfalse 
void Dijkstra(int s) {		//sΪ��� 
	fill(d, d + MAXV, INF);
	memset(num, 0, sizeof(num));
	memset(w, 0, sizeof(w));
	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++) {
			if (vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		//�Ҳ���С��INF��d[u],˵��ʣ�µĶ�������s����ͨ
		if (u == -1)return;
		vis[u] = true;		//���uΪ�ѷ���
		for (int v = 0; v < n; v++) {
			//���vδ����&&u�ܵ���v&&��uΪ�н�����ʹd[v]����
			if (vis[v] == false && G[u][v] != INF) {
				if (d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + weight[v];
					num[v] = num[u];
				}
				else if (d[u] + G[u][v] == d[v]) {
					if (w[u] + weight[v] > w[v]) {
						w[v] = w[u] + weight[v];
					}
					num[v] += num[u];
					//�ĳ�num[v]++Ҳ��
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
	int u, v;
	fill(G[0], G[0] + MAXV*MAXV, INF);//��Ҫ����ʼ��ͼ����Ȩ����Ȩ����Ȩ����� 
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);
		scanf("%d", &G[u][v]);	  //�����Ȩ	
		G[v][u] = G[u][v];		  //����ͼ�Գ�
	}
	Dijkstra(st);
	printf("%d %d\n", num[ed], w[ed]);
	return 0;
}
