#include <cstdio>
#include <cstring>
int main(){
	char a[85], n1, n2, n3;
	gets(a);
	int len = strlen(a);
	n1 = n3 = (len + 2) / 3 ;  //经过此步计算，则n1,n3的值一定是<=n2的
    n2 = len - 2 * n1;  
	for(int i = 0; i < n1 - 1; i++){	//第一个for循环只输出高-1行，底单独输出
		putchar(a[i]);
		for(int j = 0; j < n2; j++)		//空格数即为底的长度
			putchar(' ');
		printf("%c\n", a[len-1-i]);
	}
	for(int i = n1 - 1; i <= n1 + n2; i++) //最后一行先输出最左下角，再输出底，再输出最右下角
		putchar(a[i]);
	return 0;
}
/*
题意是将一串字符串排成u型，要求u的高小于等于底且高和底的差值最小。
这里将（字符串总长度+2）/3，即可求得u的高，此时高和底最接近，然后按格式输出即可。
 */