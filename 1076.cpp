/*
��Ϊֻ�ܷ���ָ���Ĳ���������ʹ��bfs��������һ��
��ΪҪ����ڵ�Ĳ�ţ����Բ����ڽӾ�������ڽӱ�
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
bool in_queue[maxn] = { false };		//�Ƿ��Ѿ��������
int bfs(int s,int L) {
	int forward = 0;	//ת����
	queue<Node> q;
	Node start;
	start.id = s;
	start.layer = 0;
	q.push(start);			//�����ʼ���õĲ�ѯ�ڵ�
	in_queue[start.id] = true;
	while (!q.empty()) {
		Node topNode = q.front();
		q.pop();
		int u = topNode.id;
		for (int i = 0; i < G[u].size(); i++) {
			Node next = G[u][i];
			next.layer = topNode.layer + 1;
			if (in_queue[next.id] == false && next.layer <= L) {//���û������Ӳ��Ҳ������������L
				q.push(next);
				in_queue[next.id] = true;//��Ϊ�����
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
		int num_follow;				//follow  i ������
		user.id = i;				//�û���Ŵ�1��n�������	
		scanf("%d", &num_follow);
		for (int j = 0; j < num_follow; j++) {
			int isFollowed;
			scanf("%d", &isFollowed);
			G[isFollowed].push_back(user);			//��Ϊ�ǹ�ע��˭����follower,�����Ǵ�temp��followerΪ1
		}
	}
	int num_Query, s;
	scanf("%d", &num_Query);
	for (int i = 0; i < num_Query; i++) {
		memset(in_queue, false, sizeof(in_queue));//ÿ�β�ѯ����ʼ��
		scanf("%d", &s);
		int forward = bfs(s, L);
		printf("%d\n", forward);
	}
	return 0;
}