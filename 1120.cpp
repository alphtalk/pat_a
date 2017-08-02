/*
利用散列去重id，很简单，不值得为此题浪费时间
*/
#include<cstdio>
int getID(int t) {
	int id = 0;
	while (t) {
		id += t % 10;
		t = t / 10;
	}
	return id;
}
int main() {
	int n, t, count = 0, s[40] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		s[getID(t)] = 1;
	}
	for (int i = 0; i < 40; i++) {
		if (s[i] != 0) count++;
	}
	printf("%d\n", count);
	bool f = false;
	for (int i = 0; i < 40; i++) {
		if (s[i] == 1) {
			if(f)	printf(" ");
			f = true;
			printf("%d", i);
		}
	}
	return 0;
}