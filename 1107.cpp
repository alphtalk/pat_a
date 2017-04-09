/*
����Ҫ�������⣬��A��B�й�ͬ���ã�B��C�й�ͬ������A��C����ͬһ���罻���磬�������һ�㣬��֪��
���⿼����Ƿ�������⣬��Ȼ�뵽���鼯���֪ʶ�㣬���ǿ�����һ��hobby[]�����ʾ���еİ��ã�hobby[x]
��ʾϲ��x���ˣ���ÿ�ζ��뵱ǰ���˵ı�ź͸�������һ�����˺ϲ������û���˸���һ������hobby[���İ���]
��Ϊ���ı�ţ��������൱���Լ����Լ��ϲ����ȵ��´α�������Щ����ʱ���Ϳ��Ը����ϲ��ˡ�
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1005;
int father[N];			//��Ÿ��׽ڵ�
int isRoot[N];			//��¼ÿ���ڵ��Ƿ��Ǹ��ڵ�
int hobby[1005];
int findfather(int root) {
	int c = root;			//���������Ľڵ㱣����������Ϊ����rootΪ���ڵ���
	while (root != father[root]) {
		root = father[root];
	}
	//·��ѹ��,��ʱroot��Ϊ���ڵ�
	while (c != father[c]) {  //����c�����ڵ�·���ϵ����нڵ㣬ʹ֮��ָ��root
		int fa = father[c];   //��ȡc��ԭ����father
		father[c] = root;	  //��c��father�޸�Ϊ���ڵ�	
		c = fa;				  //��c��father��Ϊ�½ڵ�׼��������һ���ж�
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
		father[i] = i;		  //һ��ʼÿ��Ԫ�ض��Ƕ����ļ���	
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
			if (hobby[h] == 0) {  //hobby[h]��ʾϲ��h������ĸ��ˣ�Ϊ0��ʾ��û����ϲ��
				hobby[h] = i;	  //��¼��i������ǵ�һ��ϲ���ģ���Ϊ���ڵ�	
			}
			Union(i, findfather(hobby[h])); //�Ժ�������ϲ�������գ��ϲ�����
		}
	}
	for (int i = 1; i <= n; i++) {
		isRoot[findfather(i)]++;	//ͳ�Ƴ���ÿ�����ڵ㣨���ϣ��ж��ٺ����Ԫ�أ�
	}
	int count;    //��¼������Ŀ
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
