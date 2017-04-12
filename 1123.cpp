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
	root = temp;			//ע�������ת�����ڵ�����ָ�����

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
	if (v < root->v) {			//С�ڽڵ�����壬������¸߶ȣ���Ҫ������Ҫ��
		insert(root->left, v);
		updateHeight(root);
		if (getBalance(root) == 2) {
			if (getBalance(root->left) == 1) {		//��ȡƽ�����ӣ���д�ɻ�ȡ�߶���
				R(root);
			}
			else if (getBalance(root->left) == -1) {
				L(root->left);		//ע�������Ƚ���������
				R(root);			//�ٽ��Լ�����
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