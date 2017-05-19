#include <cstdio>
#include <vector>
using namespace std;
struct Node{
	int data;
	Node *left, *right;
};
vector<int> origin, pre, preM, post, postM;
void insert(Node *&root, int data) {
	if (root == NULL) {
		root = new Node;
		root->data = data;
		root->left = root->right = NULL;
		return;
	}
	if (data < root->data) {
		insert(root->left, data);
	}
	else {
		insert(root->right, data);
	}
}
void preOrder(Node *root, vector<int>&vi) {
	if (root == NULL) {
		return;
	}
	vi.push_back(root->data);
	preOrder(root->left, vi);
	preOrder(root->right, vi);
}
void preOrderMirror(Node *root, vector<int>&vi) {
	if (root == NULL) {
		return;
	}
	vi.push_back(root->data);
	preOrderMirror(root->right, vi);
	preOrderMirror(root->left, vi);
}
void postOrder(Node *root, vector<int>&vi) {
	if (root == NULL) {
		return;
	}
	postOrder(root->right, vi);
	postOrder(root->left, vi);
	vi.push_back(root->data);
}
void postOrderMirror(Node *root, vector<int>&vi) {
	if (root == NULL) {
		return;
	}
	postOrderMirror(root->right, vi);
	postOrderMirror(root->left, vi);
	vi.push_back(root->data);
}
int main() {
	int n, data;
	Node *root = NULL;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		insert(root, data);
		origin.push_back(data);
	}
	preOrder(root, pre);
	preOrderMirror(root, preM);
	postOrder(root, post);
	postOrderMirror(root, postM);
	if (origin == pre) {
		puts("YES");
		for (int i = 0; i < post.size(); i++) {
			printf("%d", post[i]);
			if (i < post.size() - 1) {
				putchar(' ');
			}
		}
	}
	else if (origin == preM) {
		puts("YES");
		for (int i = 0; i < postM.size(); i++) {
			printf("%d", postM[i]);
			if (i < postM.size() - 1) {
				putchar(' ');
			}
		}
	}
	else {
		puts("NO");
	}
	return 0;
}