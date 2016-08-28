#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main(){
	char N[105];
	gets(N);
	int len=strlen(N);
	int sum=0;
	for(int i=0;i<len;i++)
		sum+=(N[i]-'0');
	char spell[10][7]={"zero","one","two","three","four","five","six","seven",
		"eight","nine"};
	int divice[5]={0},k;	
	if(sum==0) 	divice[k++]=sum%10;
	while(sum){
		divice[k++]=sum%10;
		sum/=10;
	}
	for(int i=k-1;i>=0;i--){ 
		printf("%s", spell[divice[i]]);
		if(i!=0)	putchar(' '); 
	} 
	return 0;
}
