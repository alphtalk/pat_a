#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N = 100005;
vector<int> G[N], root;	//�ڽӱ�洢,root��ʾdfs����Զ���
int max_deep = 0, cur_root;
bool vis[N] = { false };
void dfs(int node, int height) {
	vis[node] = true;
	if (height > max_deep) {
		max_deep = height;
		root.clear();
		root.push_back(cur_root);//��ǰ���������ĸ��ڵ�֮һ
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
void dfs_components(int start) { //dfs�ҳ���ͨ������Ŀ
		vis[start] = true;
		for (int i = 0; i < G[start].size(); i++) {	//ѭ��dfs
			if (vis[G[start][i]] == false)
				dfs_components(G[start][i]);
		}
		return;
}
int main() {
	int a, b, n, count = 0;//count��ʾ��ͨ��������Ŀ
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for (int i = 1; i <= n; i++){	//����ÿ����㣬�ҳ���ͨ��Ŀ
		if (vis[i] == false){
			count++;				//���δ���ʣ���ʾһ���µ���ͨ����
			dfs_components(i);
		}
	}
	if (count > 1)
		printf("Error: %d components\n", count);
	else{	//����ͨͼ
		for (int i = 1; i <= n; i++){	//ѭ������ÿ�����
			memset(vis, false, sizeof(vis));	//��ʼ��Ϊfalse
			cur_root = i;	//����ÿ�α��������
			dfs(i, 1);
		}
		printf("size %d",root.size());
		for (int i = 0; i < root.size(); i++)	//���
			printf("%d\n", root[i]);
	}

	return 0;
}

