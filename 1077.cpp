#include <cstdio>
#include <cstring>
int n, minLen = 256, ans = 0;
char s[100][256];
int main() {
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		gets(s[i]);							//读取一行
		int len = strlen(s[i]);				//计数
		if (len < minLen) minLen = len;		//防止越界
		for (int j = 0; j < len / 2; j++) { //改变次序，变成求公共前缀
			char temp = s[i][j];
			s[i][j] = s[i][len - j - 1];
			s[i][len - j - 1] = temp;
		}
	}
	for (int i = 0; i < minLen; i++) {
		char c = s[0][i];
		bool same = true;
		for (int j = 1; j < n; j++) {		//依次与n个字符串相比较
			if (c != s[j][i]) {
				same = false;
				break;						//一旦遇到不相同可提前跳出
			}
		}
		if (same) ans++;					//每一个字母完全相同，公共前缀加一
		else break;
	}
	if (ans) {								//倒序输出前缀
		for (int i = ans - 1; i >= 0; i--) {
			printf("%c", s[0][i]);
		}
	}
	else {
		printf("nai");
	}
	return 0;
}
