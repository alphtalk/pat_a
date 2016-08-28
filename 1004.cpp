#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N=110;
int leaf[N]={0};				//存放每层的叶子节点数
vector<int> G[N];				//邻接矩阵存放树
int max_h=1;					//初始树的深度为1
void DFS(int index,int h){
	max_h=max(h,max_h);
	if(G[index].size()==0){		//如果是叶子节点，更新深度数组并返回
		leaf[h]++;
		return;
	}
	for(int i=0;i<G[index].size();i++)//如果不是叶子节点，则枚举他的所有子节点并且深度+1
		DFS(G[index][i],h+1);
}
int main(){
	int m,n,parent,child,k;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&parent,&k);
		for(int j=0;j<k;j++){
			scanf("%d",&child);
			G[parent].push_back(child);
		}
	}
	DFS(1,1);
	printf("%d",leaf[1]);
	for(int i=2;i<=max_h;i++)
		printf(" %d",leaf[i]);
	return 0;
}