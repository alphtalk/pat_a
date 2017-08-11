#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 0x3fffffff;
const int MAX = 1015;
int N, M, K, Ds;
bool vis[MAX] = { false };
int G[MAX][MAX],d[MAX], minIde = -1;
double minAve = INF, maxDis = -1;

void Dijkstra(int s) {			//�Ͻ�˹�����㷨����ĸ�����̾��뱣����d������
	memset(vis, false, sizeof(vis));		//������ĵϽ�˹����ÿ�ζ���ʼ��vis����
	fill(d, d + MAX, INF);
	d[s] = 0;
	for (int i = 1; i <= N + M; i++) {		//������������֮����ܻᾭ�����Ӽ���վ��·������<=N+M
		int u = -1, min = INF;
		for (int j = 1; j <= N + M; j++) {
			if (vis[j] == false && d[j] < min) {
				u = j;
				min = d[j];
			}
		}
		if (u == -1)	return;
		vis[u] = true;
		for (int v = 1; v <= N + M; v++) {
			if (vis[v] == false  && G[u][v]!=INF) {
				if(d[u] + G[u][v] < d[v])
					d[v] = G[u][v] + d[u];
			}
		}
	}
}
int getId(char str[]) {
	int i = 0, len = strlen(str), id = 0;
	while (i < len) {
		if (str[i] != 'G') {
			id = id * 10 + (str[i] - '0');
		}
		i++;
	}
	if (str[0] == 'G')	return N + id;
	else return id;
}
int main() {
	fill(G[0], G[0] + MAX*MAX, INF);//��ʼ��ͼ�����ҵ��ϸ磬���˰��Сʱ�Ĵ���
	scanf("%d%d%d%d", &N, &M, &K, &Ds);
	char t1[5], t2[5];
	int u, v, w;
	for (int i = 0; i < K; i++) {
		scanf("%s %s %d", &t1, &t2, &w);//���ַ�����������Ҫ���ǵ���λת��������������Ϊ��һλ�ˣ��ַѰ��Сʱ
		u = getId(t1);
		v = getId(t2);
		G[v][u] = G[u][v] = w;
	}
	
	for (int i = N + 1; i <= N + M; i++) {//��ÿ������վ������������񷿵ľ���
		int Dis = INF;				//Disÿһ�����¸�ֵΪ�����һ�߽�����һ�αȽ�
		double Ave = 0;
		Dijkstra(i);
		for (int j = 1; j <= N; j++) {
			if (d[j] > Ds) {
				Dis = -1;			//û�и������з�������ѭ��������������񷿾���
				break;
			}
			if (d[j] < Dis) {		//���ÿ������վ������񷿵ľ���
				Dis = d[j];
			}
			Ave += (double)d[j] / N;

		}
		if (Dis == -1)	continue;
		if (Dis > maxDis) {
			maxDis = Dis;
			minAve = Ave;
			minIde = i;
		}
		else if (Dis == maxDis&&minAve > Ave) {
			minAve = Ave;
			minIde = i;
		}
	}
	if (minIde == -1) {
		printf("No Solution\n");
	}
	else {
		printf("G%d\n", minIde - N);
		printf("%.1f %.1f", maxDis, minAve);
	}
	return 0;
}