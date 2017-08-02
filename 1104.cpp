/*
´¿´âÕÒ¹æÂÉ
*/
#include <cstdio>
int main() {
	int n;
	double sum = 0, t;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lf", &t);
		sum += t*i*(n - i + 1);
	}
	printf("%.2f", sum);
	return 0;
}