#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N = 100005;
vector<int> G[N], root;	//邻接表存储,root表示dfs的最远结果
int max_deep = 0, cur_root;
bool vis[N] = { false };
void dfs(int node, int height) {
	vis[node] = true;
	if (height > max_deep) {
		max_deep = height;
		root.clear();
		root.push_back(cur_root);//当前结点是最深的根节点之一
		printf("h max %d%d\n", height,max_deep);
	}
	else if (height == max_deep) {
		if (root[root.size() - 1] != cur_root)
		root.push_back(cur_root);
		printf("size %d\n", root.size());
	}
	for (int i = 0; i < G[node].size(); i++) {
		if (vis[node] == false)
			dfs(G[node][i], height + 1);
	}
	return;
}
void dfs_components(int start) { //dfs找出连通分量数目
		vis[start] = true;
		for (int i = 0; i < G[start].size(); i++) {	//循环dfs
			if (vis[G[start][i]] == false)
				dfs_components(G[start][i]);
		}
		return;
}
int main() {
	int a, b, n, count = 0;//count表示连通分量的数目
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for (int i = 1; i <= n; i++){	//遍历每个结点，找出连通数目
		if (vis[i] == false){
			count++;				//结点未访问，表示一个新的连通分量
			dfs_components(i);
		}
	}
	if (count > 1)
		printf("Error: %d components\n", count);
	else{	//是连通图
		for (int i = 1; i <= n; i++){	//循环遍历每个结点
			memset(vis, false, sizeof(vis));	//初始化为false
			cur_root = i;	//保存每次遍历的起点
			dfs(i, 1);
		}
		printf("size %d",root.size());
		for (int i = 0; i < root.size(); i++)	//输出
			printf("%d\n", root[i]);
	}

	return 0;
}

