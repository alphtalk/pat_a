#include<cstdio>
struct Poly{
	int ex;
	double co;
}Poly[1001];
int main(){
	int k1,k2,ex,count=0;
	double temp[2005]={0},co;
	scanf("%d",&k1);
	for(int i=0;i<k1;i++)
		scanf("%d%lf",&Poly[i].ex,&Poly[i].co);
	scanf("%d",&k2);
	for(int i=0;i<k2;i++){
		scanf("%d%lf",&ex,&co);
		for(int j=0;j<k1;j++)
			temp[ex+Poly[j].ex]+=(co*Poly[j].co);
	}
	for(int i=0;i<=2000;i++)
		if(temp[i]!=0.0)	count++;
	printf("%d",count);
	for(int i=2000;i>=0;i--)
		if(temp[i]!=0.0)	printf(" %d %.1f",i,temp[i]);
	return 0;
}