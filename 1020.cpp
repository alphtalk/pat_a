#include <cstdio>
#include <queue>
using namespace std;
const int MAX = 35;
int in[MAX], post[MAX], N;
struct Node {
	int data;
	Node *rchild;
	Node *lchild;
};
Node* create(int postL, int postR, int inL, int inR) {
	if (postL > postR) {
		return NULL;
	}
	Node *root = new Node;
	root->data = post[postR];
	int k;
	for (k = inL; k <= inR; k++) {
		if (in[k] == post[postR]) {
			break;
		}
	}
	int numLeft = k - inL;
	root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
	root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
	return root;
}
int num = 0;
void LayerOrder(Node *root) {
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node *now = q.front();
		q.pop(); 
		printf("%d", now->data);
		num++;
		if (num < N) {
			putchar(' ');
		}
		if (now->lchild) {
			q.push(now->lchild);
		}
		if (now->rchild) {
			q.push(now->rchild);
		}
	}
}
int main() { 

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &post[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &in[i]);
	}
	Node *root = create(0, N - 1, 0, N - 1);
	LayerOrder(root);
	return 0; 
}