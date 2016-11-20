/*
这题做的很顺利，题的意思是输入一个数N，判断这个数在base进制下是不是回文数，并输出这个回文数。首先将这个数字转换成
base进制，这里模拟手算转换进制的方法（取余），然后依次判断第一个数与最后一个数，第二个数与倒数第二个数……是否相同。最后输出。
注意：根据题意0也是回文数，故要单独判断一下。
 */
#include <cstdio>
int B[100];
int N,base;
int converse(int b){
	int i = 0;
	while(N){
		B[i++]=N%base;
		N=N/base;
	}
	return i;
}
int isPalindromic(int len){
	for(int i=0;i<len;i++){
		if(B[i]!=B[len-i-1])
			return 0;
	}
	return 1;
}
int main(){
	scanf("%d%d", &N, &base);
	if(N==0) printf("Yes\n0");//对0这个回文数特殊处理
	else{
		int len = converse(base);
		if(isPalindromic(len))
			printf("Yes");
		else printf("No");
		putchar('\n');
		for(int i=len-1;i>=0;i--){
			if(i!=(len-1))	putchar(' ');
			printf("%d",B[i]);
		}
	}
	return 0;
}
