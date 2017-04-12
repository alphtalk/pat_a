#include <cstdio>
#include <algorithm>
using namespace std;
struct node { 
	int v, height;
	node *lchild, *rchild;
} *root;
node* newNode(int v) {
	node* Node = new node;    // 申请一个node型变量的地址空间
	Node->v = v;    // 结点权值为v
	Node->height = 1;    // 结点高度初始为1
	Node->lchild = Node->rchild = NULL;    // 初始状态下没有左右孩子
	return Node;    // 返回新建结点的地址
}
int getHeight(node* root) {
	if (root == NULL) return 0;    // 空结点高度为0
	return root->height;
}
// 更新结点root的height
void updateHeight(node* root) {
	// max(左孩子的height, 右孩子的height) + 1
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
// 计算结点root的平衡因子
int getBanlance(node* root) {
	// 左子树高度减右子树高度
	return getHeight(root->lchild) - getHeight(root->rchild);
}
// 左旋（lchild Rotation）
void L(node* &root) {
	node* temp = root->rchild;    // root指向结点A，temp指向结点B
	root->rchild = temp->lchild;    // Step 1
	temp->lchild = root;    // Step 2
	updateHeight(root);    // 更新结点A的高度
	updateHeight(temp);    // 更新结点B的高度
	root = temp;    // Step 3
}
// 右旋（rchild Rotation）
void R(node* &root) {
	node* temp = root->lchild;    // root指向结点B，temp指向结点A
	root->lchild = temp->rchild;    // Step 1
	temp->rchild = root;    // Step 2
	updateHeight(root);    // 更新结点B的高度
	updateHeight(temp);    // 更新结点A的高度
	root = temp;    // Step 3
}
void insert(node* &root, int v) {
	if (root == NULL) {    // 到达空结点
		root = newNode(v);
		return;
	}
	if (v < root->v) {    // v比根结点权值小
		insert(root->lchild, v);    // 往左子树插入
		updateHeight(root);    // 更新树高
		if (getBanlance(root) == 2) {
			if (getBanlance(root->lchild) == 1) {    // LL型
				R(root);
			}
			else if (getBanlance(root->lchild) == -1) {    // LR型
				L(root->lchild);
				R(root);
			}
		}
	}
	else {    // v比根结点权值大
		insert(root->rchild, v);    // 往右子树插入
		updateHeight(root);    // 更新树高
		if (getBanlance(root) == -2) {
			if (getBanlance(root->rchild) == -1) {    // RR型
				L(root);
			}
			else if (getBanlance(root->rchild) == 1) {    // RL型
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


