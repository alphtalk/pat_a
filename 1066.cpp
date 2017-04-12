#include <cstdio>
#include <algorithm>
using namespace std;
struct node { 
	int v, height;
	node *lchild, *rchild;
} *root;
node* newNode(int v) {
	node* Node = new node;    // ����һ��node�ͱ����ĵ�ַ�ռ�
	Node->v = v;    // ���ȨֵΪv
	Node->height = 1;    // ���߶ȳ�ʼΪ1
	Node->lchild = Node->rchild = NULL;    // ��ʼ״̬��û�����Һ���
	return Node;    // �����½����ĵ�ַ
}
int getHeight(node* root) {
	if (root == NULL) return 0;    // �ս��߶�Ϊ0
	return root->height;
}
// ���½��root��height
void updateHeight(node* root) {
	// max(���ӵ�height, �Һ��ӵ�height) + 1
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
// ������root��ƽ������
int getBanlance(node* root) {
	// �������߶ȼ��������߶�
	return getHeight(root->lchild) - getHeight(root->rchild);
}
// ������lchild Rotation��
void L(node* &root) {
	node* temp = root->rchild;    // rootָ����A��tempָ����B
	root->rchild = temp->lchild;    // Step 1
	temp->lchild = root;    // Step 2
	updateHeight(root);    // ���½��A�ĸ߶�
	updateHeight(temp);    // ���½��B�ĸ߶�
	root = temp;    // Step 3
}
// ������rchild Rotation��
void R(node* &root) {
	node* temp = root->lchild;    // rootָ����B��tempָ����A
	root->lchild = temp->rchild;    // Step 1
	temp->rchild = root;    // Step 2
	updateHeight(root);    // ���½��B�ĸ߶�
	updateHeight(temp);    // ���½��A�ĸ߶�
	root = temp;    // Step 3
}
void insert(node* &root, int v) {
	if (root == NULL) {    // ����ս��
		root = newNode(v);
		return;
	}
	if (v < root->v) {    // v�ȸ����ȨֵС
		insert(root->lchild, v);    // ������������
		updateHeight(root);    // ��������
		if (getBanlance(root) == 2) {
			if (getBanlance(root->lchild) == 1) {    // LL��
				R(root);
			}
			else if (getBanlance(root->lchild) == -1) {    // LR��
				L(root->lchild);
				R(root);
			}
		}
	}
	else {    // v�ȸ����Ȩֵ��
		insert(root->rchild, v);    // ������������
		updateHeight(root);    // ��������
		if (getBanlance(root) == -2) {
			if (getBanlance(root->rchild) == -1) {    // RR��
				L(root);
			}
			else if (getBanlance(root->rchild) == 1) {    // RL��
				R(root->rchild);
				L(root);
			}
		}
	}
}
int main() {
	int n, v;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v);
		insert(root, v);
	}
	printf("%d", root->v);
	return 0;
}


