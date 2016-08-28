#include<cstdio>
double ex[1005]={};
int main(){
	double a;
	int k,n,count=0;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d%lf",&n,&a);
		ex[n]=a;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d%lf",&n,&a);
		ex[n]+=a;
	}
	for(int i=0;i<1005;i++){
		if(ex[i]!=0)
			printf("%.lf",ex[i]);
	}
	return 0;
} 
