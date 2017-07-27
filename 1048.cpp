#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100005;
int coins[maxn];
void twoPointers(int n,int m) {
	int i = 0 , j = n - 1;
	while (i < j) {
		if (coins[i] + coins[j] == m) break;
		else if (coins[i] + coins[j] < m) {
			i++;
		}
		else j--;
	}
	if (i < j) {
		printf("%d %d\n", coins[i], coins[j]);
	}
	else printf("No Solution");
}
int main() {
	int m, n;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &coins[i]);
	}
	sort(coins, coins + n);
	twoPointers(n, m);
	
	return 0;
}