#include<cstdio>
#include<cstring>
struct Person{
	char ID[20];
	char unlock[10]={'2','4',':','6','0',':','6','0'};
	char lock[10]={'0','0',':','0','0',':','0','0'};
};
int main(){
	int M;
	Person p,temp1,temp2;
	scanf("%d",&M);
	for(int i=0;i<M;i++){
		int h,m,s,hh,mm,ss,h1,h2,m1,m2,s1,s2;
		scanf("%s%s%s",p.ID,p.unlock,p.lock);
		sscanf(p.lock,"%d:%d:%d",&h,&m,&s);
		sscanf(p.unlock,"%d:%d:%d",&hh,&mm,&ss);
		sscanf(temp1.lock,"%d:%d:%d",&h1,&m1,&s1);
		sscanf(temp2.unlock,"%d:%d:%d",&h2,&m2,&s2);
		if(h>h1)	temp1=p;
		else if(h==h1&&m>m1)	temp1=p;
		else if(m==m1&&s>s1)	temp1=p;
		if(hh<h2)	temp2=p;
		else if(hh==h2&&mm<m2)	temp2=p;
		else if(mm==m2&&ss<s2)	temp2=p;
		
	}
	printf("%s %s",temp2.ID,temp1.ID);
	return 0; 
} 
