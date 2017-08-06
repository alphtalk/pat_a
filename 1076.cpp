/*
因为只能访问指定的层数，所以使用bfs便利更好一点
因为要保存节点的层号，所以不用邻接矩阵而用邻接表
*/
#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
const int maxn = 1005;

struct Node {
	int id, layer;
};
vector<Node> G[maxn];
bool in_queue[maxn] = { false };		//是否已经加入队列
int bfs(int s,int L) {
	int forward = 0;	//转发数
	queue<Node> q;
	Node start;
	start.id = s;
	start.layer = 0;
	q.push(start);			//放入初始化好的查询节点
	in_queue[start.id] = true;
	while (!q.empty()) {
		Node topNode = q.front();
		q.pop();
		int u = topNode.id;
		for (int i = 0; i < G[u].size(); i++) {
			Node next = G[u][i];
			next.layer = topNode.layer + 1;
			if (in_queue[next.id] == false && next.layer <= L) {//如果没有入过队并且不超过层的上限L
				q.push(next);
				in_queue[next.id] = true;//设为已入队
				forward++;
			}
		}
	}
	return forward;
}
int main() {
	Node user;
	int n, L;
	scanf("%d%d", &n, &L);
	for (int i = 1; i <= n; i++) {
		int num_follow;				//follow  i 的人数
		user.id = i;				//用户编号从1到n，看清楚	
		scanf("%d", &num_follow);
		for (int j = 0; j < num_follow; j++) {
			int isFollowed;
			scanf("%d", &isFollowed);
			G[isFollowed].push_back(user);			//因为是关注了谁属于follower,所以是从temp到follower为1
		}
	}
	int num_Query, s;
	scanf("%d", &num_Query);
	for (int i = 0; i < num_Query; i++) {
		memset(in_queue, false, sizeof(in_queue));//每次查询都初始化
		scanf("%d", &s);
		int forward = bfs(s, L);
		printf("%d\n", forward);
	}
	return 0;
}