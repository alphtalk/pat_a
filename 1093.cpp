#include<cstdio>
#include<cstring>
const int MAX = 100005;
const int MOD = 1000000007;
int main() {
	char s[MAX];
	gets(s);
	int len = strlen(s), count = 0;
	int left_P[MAX] = { 0 }, right_T[MAX] = {0};
	for (int i = 0; i < len; i++) {//����һ��forѭ�������ÿһλ���P�ĸ������ұ�T�ĸ���
		if (i > 0) {				//if(i>0)һ��������������if��ǰ�棬�Ȱ���һλ��ֵ�������ټ�����һλ��ֵ
			left_P[i] = left_P[i - 1];
			right_T[len - 1 - i] = right_T[len - i];
		}
		if (s[i] == 'P')	left_P[i]++;
		if (s[len - 1 - i] == 'T')	right_T[len - 1 - i]++;
	}
	for (int i = 0; i < len; i++) {
		//�ٽ���һ��ѭ��,����ÿһ��A����P����T��Ϊ��һλ�γ�pat�ĸ�����ÿһλ�γ�pat�ĸ���֮�ͼ�Ϊ�ܸ���
		if (s[i] == 'A')
			count = (count + left_P[i] * right_T[i]) % MOD;
	}
	printf("%d", count);
	return 0;
}