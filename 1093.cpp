#include<cstdio>
#include<cstring>
const int MAX = 100005;
const int MOD = 1000000007;
int main() {
	char s[MAX];
	gets(s);
	int len = strlen(s), count = 0;
	int left_P[MAX] = { 0 }, right_T[MAX] = {0};
	for (int i = 0; i < len; i++) {//先用一个for循环计算出每一位左边P的个数和右边T的个数
		if (i > 0) {				//if(i>0)一定是在下面两个if的前面，先把上一位的值传过来再计算这一位的值
			left_P[i] = left_P[i - 1];
			right_T[len - 1 - i] = right_T[len - i];
		}
		if (s[i] == 'P')	left_P[i]++;
		if (s[len - 1 - i] == 'T')	right_T[len - 1 - i]++;
	}
	for (int i = 0; i < len; i++) {
		//再进行一遍循环,对于每一个A，左P×右T即为这一位形成pat的个数，每一位形成pat的个数之和即为总个数
		if (s[i] == 'A')
			count = (count + left_P[i] * right_T[i]) % MOD;
	}
	printf("%d", count);
	return 0;
}