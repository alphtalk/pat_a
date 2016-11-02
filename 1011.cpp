//这道题有点醉，挺简单的一道题愣是搞了一个半小时，题意就是从三行中每一行找出最大数相乘得sum，顺便记录下最大值所在位置，
//一会儿输出，再将sum套入公式(sum*0.65-1)*2,最坑的一个地方是我用double存的数据，看样例是37.98以为是四舍五入，所以在公式
//后边加了个0.005，结果全错，调半天把0.005去掉，本机显示37.97，提交却对了。以后不是要求精度5,6位的用float吧！！！
#include<cstdio>
int main(){
	float a,b,c,sum=1;
	int j=0;
	char which[3];
	for(int i=0;i<3;i++){
		scanf("%f %f %f",&a,&b,&c);
		if(a>b&&a>c){
			sum*=a;
			which[j++]='W';
		}
		else if(b>a&&b>c){
			sum*=b;
			which[j++]='T';
		}
		else{
			sum*=c;
			which[j++]='L';
		}
	}
	for(int i=0;i<3;i++)	printf("%c ", which[i]);
	printf("%.2f", (sum*0.65-1)*2);
	return 0;
}
