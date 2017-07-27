#include <cstdio>
const int maxn = 100005;
int sum[maxn];
int nearm = 0x7fffffff;
int upper_bound(int L, int R, int key) {	//返回[L,R)区间内第一个大于key的位置
	int left = L, right = R, mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (sum[mid] > key) right = mid;
		else left = mid + 1;
	}
	return left;
}
int main(){
	int n, m;
	sum[0] = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &sum[i]);
		sum[i] += sum[i - 1];   //sum[i]为从第1个到第i个元素之和
	}
	for (int i = 1; i <= n; i++) {
		int j = upper_bound(i, n + 1, sum[i - 1] + m);	//求右端点(若存在key则越过一个，若不存在则大于的第一个)
		if (sum[j - 1] - sum[i - 1] == m) {//越过一个，需要j-1
			nearm = m;
			break;
		}
		else if (j <= n && sum[j] - sum[i - 1] < nearm) {//找出最靠近m的值nearm
			nearm = sum[j] - sum[i - 1];
		}
	}

	for (int i = 1; i <= n; i++) {
		int j = upper_bound(i, n + 1, sum[i - 1] + nearm);
		if (sum[j - 1] - sum[i - 1] == nearm) {
			printf("%d-%d\n", i, j - 1);
		}
	}
	return 0;
}