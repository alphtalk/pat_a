#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;

const int MAX = 205;
const int INF = 0x3fffffff;
int G[MAX][MAX], d[MAX], w[MAX], weight[MAX],pre[MAX],p[MAX];//p数组为
bool vis[MAX] = { false };
map<string, int> city_id;
map<int, string> id_city;
int num[MAX];
int  n, k, numCity = 0;
int cityToId(string city) {
	if (city_id.find(city) != city_id.end()) {		//有对应id
		return city_id[city];
	}
	else {
		city_id[city] = numCity;
		id_city[numCity] = city;
		return numCity++;
	}
}
void print(int v) {
	if (v == 0) {
		cout << id_city[v];
		return;
	}
	print(pre[v]);
	cout << "->" << id_city[v];
}
void Dijkstra(int s) {
	for (int i = 0; i < n; i++)	pre[i] = i;
	fill(d, d + MAX, INF);
	num[s] = 1;
	d[s] = 0;
	w[s] = weight[s];
	for (int i = 0; i < n; i++) {
		int min = INF, u = -1;
		for (int j = 0; j < n; j++) {
			if (vis[j] == false && d[j] < min) {
				min = d[j];
				u = j;
			}
		}
		if (u == -1)	return;
		vis[u] = true;
		for (int v = 0; v < n; v++) {
			if (vis[v] == false) {
				if (d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + weight[v];
					p[v] = p[u] + 1;		//起点到v点最短路径上的顶点个数加了一个点u
					num[v] = num[u];
					pre[v] = u;
				}
				else if (d[u] + G[u][v] == d[v]) {
					num[v] += num[u];
					if (w[u] + weight[v] > w[v]) {	//以u为中介点使w[v]更优
						w[v] = w[u] + weight[v];
						p[v] = p[u] + 1;
						pre[v] = u;
					}
					else if (w[u] + weight[v] == w[v]) {
						//最短距离相同且以u为中介点权也相同的情况下,
						//以u为中介路径顶点个数+1还比原来顶点个数少的话则平均点权就大
						if (p[u] + 1 < p[v]) {
							p[v] = p[u] + 1;
							pre[v] = u;
						}
					}
				}
			}
		}
	}
}
int main() {

	int h;
	string city, start;	//城市名和起点城市名
	fill(G[0], G[0] + MAX*MAX, INF);
	scanf("%d%d", &n, &k);
	cin >> start;
	weight[cityToId(start)] = 0;
	for (int i = 1; i <= n - 1; i++) {
		cin >> city >> h;
		weight[cityToId(city)] = h;
	}
	int c;
	string city1, city2;
	for (int i = 0; i < k; i++) {
		cin >> city1 >> city2 >> c;
		G[cityToId(city1)][cityToId(city2)] = c;
		G[cityToId(city2)][cityToId(city1)] = c;
	}
	Dijkstra(0);
	int rom = city_id["ROM"];
	printf("%d %d %d %d\n", num[rom], d[rom], w[rom], w[rom] / p[rom]);
	print(rom);
	return 0;
}