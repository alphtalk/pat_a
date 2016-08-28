#include<cstdio>
#include<cstring>
int main(){
	int a,b;
	char sum[10];
	scanf("%d%d",&a,&b);
	int total=a+b;
	if(total<0){			  //如果和为负数，则先把负号输出，并变为正数，方便计算 
		printf("-");
		total=-total;
	}
	sprintf(sum,"%d",total);  //将和的每一位数字存放到sum中 
	int len=strlen(sum);	
	for(int i=0;i<len;i++){
		if((len-i)%3==0&&i!=0)//若要输出的元素不是第一个且后面有3的倍数个元素的时候则应该在它之前输出一个',' 
		putchar(',');
		putchar(sum[i]);
	}
	return 0;
	
}
