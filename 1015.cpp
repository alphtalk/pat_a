/*
关于题意的理解：
73在10进制下的反转数是37，两个都是素数。
23的二进制是10111，反转之后是11101，也就是39，两个都是素数。
23在十进制下的反转数是32，32不是素数。
每读入一个数字，先对其判断是否是素数，然后求出其反转数，判断它是不是素数。
本来用的是一个数组存储的翻转数的各个位，然后再把数组各位按权相加转换成一个数，
后来发现还可以简化成直接用一个变量即时的算出这个数。
注意：
不要判忘记断1不是素数。
输入的数和转化后的数都必须是素数。 
*/
#include <cstdio>
#include <cstring>
#include <cmath>
int isprime(int n){
	if(n == 1)	return 0;
	for(int i = 2; i <= sqrt(n); i++)
		if(n % i == 0)	return 0;
	return 1;
}
int converse(int n1, int n2){	//将n1转换为n2进制反转之后的数组
	int rever = 0;
	 while (n1) {
	 	//注意理解这一步每往后增加一位即将当前数乘以进制并加上刚算出的那一位
	 	//比如101用除2取余法你是先得到的左1，第一次不需要乘以进制，所以rever初始化为0
	 	//然后是0你要将此时的数1乘以2再加上刚得到的这一位0
	 	//十进制可能更好理解一点比如123，先得1再得2就是1×10+2=12，再得3,就是12*10+3=123
        rever = rever * n2 + n1 % n2;	
        n1 /= n2;						
   	 }
   	 return rever;	
}
int main(){
	int n1, n2;
	while(scanf("%d", &n1)){
		if(n1 >= 0)	scanf("%d", &n2);
		else break;						//负数结束
		if(isprime(n1)&&isprime(converse(n1, n2)))	puts("Yes");
		else puts("No");
	}
	return 0;
}
