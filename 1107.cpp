/*
首先要看懂题意，若A和B有共同爱好，B和C有共同爱好则A和C属于同一个社交网络，理解了这一点，就知道
这题考察的是分类的问题，自然想到并查集这个知识点，我们可以用一个hobby[]数组表示所有的爱好，hobby[x]
表示喜欢x的人，把每次读入当前的人的编号和跟她爱好一样的人合并，如果没有人跟他一样，则hobby[他的爱好]
设为他的编号，这样就相当于自己跟自己合并，等到下次别人有这些爱好时，就可以跟他合并了。
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1005;
int father[N];			//存放父亲节点
int isRoot[N];			//记录每个节点是否是根节点
int hobby[1005];
int findfather(int root) {
	int c = root;			//将传进来的节点保存下来，因为过后root为根节点了
	while (root != father[root]) {
		root = father[root];
	}
	//路径压缩,此时root已为根节点
	while (c != father[c]) {  //遍历c到根节点路径上的所有节点，使之都指向root
		int fa = father[c];   //获取c的原来的father
		father[c] = root;	  //把c的father修改为根节点	
		c = fa;				  //把c的father作为新节点准备进行下一次判断
	}
	return root;
}
void Union(int a, int b) {
	int fatherA = findfather(a);
	int fatherB = findfather(b);
	if (fatherA != fatherB) {
		father[fatherA] = fatherB;
	}
}
void init(int n) {
	for (int i = 0; i <= n; i++) {
		father[i] = i;		  //一开始每个元素都是独立的集合	
	}
}
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int n, temp, h;
	scanf("%d", &n);
	init(n);
	for (int i = 1; i <= n; i++) {
		scanf("%d:", &temp);
		for (int j = 0; j < temp; j++) {
			scanf("%d", &h);
			if (hobby[h] == 0) {  //hobby[h]表示喜欢h活动的是哪个人，为0表示还没有人喜欢
				hobby[h] = i;	  //记录下i这个人是第一个喜欢的，设为根节点	
			}
			Union(i, findfather(hobby[h])); //以后再有人喜欢，（收）合并儿子
		}
	}
	for (int i = 1; i <= n; i++) { 
		isRoot[findfather(i)]++;	//统计出了每个根节点（集合）有多少后代（元素）
	}
	int count;    //记录集合数目
	for (int i = 1; i <= n; i++) {
		if (isRoot[i] != 0) {
			count++;
		}
	}
	printf("%d\n", count);
	sort(isRoot + 1, isRoot + n + 1, cmp);
	for (int i = 1; i <= count; i++) {
		printf("%d", isRoot[i]);
		if (i < count) printf(" ");
	}
	return 0;
}
