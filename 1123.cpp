#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct node {
	int v, height;
	node *left, *right;
} *root;
node* newNode(int v) {
	node *n = new node;
	n->v = v;
	n->height = 1;
	n->left = n->right = NULL;
	return n;
}
int getHeight(node *root) {
	if (root == NULL) {
		return 0;
	}
	return root->height;
}
void updateHeight(node *root) {
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}
int getBalance(node *root) {
	return getHeight(root->left) - getHeight(root->right);
}
void L(node *&root) {
	node *temp = root->right;
	root->right = temp->left;
	temp->left = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;			//注意这里，旋转完后根节点重新指向最顶点

}
void R(node *&root) {
	node *temp = root->left;
	root->left = temp->right;
	temp->right = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void insert(node *&root, int v) {
	if (root == NULL) {
		root = newNode(v);
		return;
	}
	if (v < root->v) {			//小于节点往左插，插完更新高度，不要忘啊不要忘
		insert(root->left, v);
		updateHeight(root);
		if (getBalance(root) == 2) {
			if (getBalance(root->left) == 1) {		//获取平衡因子，别写成获取高度了
				R(root);
			}
			else if (getBalance(root->left) == -1) {
				L(root->left);		//注意这里先将左孩子左旋
				R(root);			//再将自己右旋
			}
		}
	}
	else {
		insert(root->right, v);
		updateHeight(root);
		if (getBalance(root) == -2) {
			if (getBalance(root->right) == -1) {
				L(root);
			}
			else if (getBalance(root->right) == 1) {
				R(root->right);
				L(root);
			}
		}
	}
	
}
void levelOrder(node *root, int n) {
	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		node *front = q.front();
		q.pop();
		printf("%d", front->v);
		n--;
		printf(n ? " " : "\n");
		if (front->left) {
			q.push(front->left);
		}
		if (front->right) {
			q.push(front->right);
		}
	}
}
bool isCompleteTree(node *root, int n) {
	queue<node*> q;
	q.push(root);
	while (n) {
		node *front = q.front();
		q.pop();
		if (front == NULL) {
			return false;
		}
		n--;
		q.push(front->left);
		q.push(front->right);
	}
	return true;
}  
int main() {
	int n, v;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v);
		insert(root, v);
	}
	levelOrder(root, n);
	printf(isCompleteTree(root, n) ? "YES\n" : "NO\n");
	return 0;
}