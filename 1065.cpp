#include<cstdio>
typedef long long LL;
int main() {
	int n;
	LL a, b, c;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld%lld", &a, &b, &c);
		LL res = a + b;
		bool flag;
		if (a > 0 && b > 0 && res < 0) flag = true;
		else if (a < 0 && b < 0 && res >= 0) flag = false;
		else if (res > c) flag = true;
		else flag = false;
		if(flag)
			printf("Case #%d: true\n", i + 1);
		else
			printf("Case #%d: false\n", i + 1);

	}
	return 0;
}