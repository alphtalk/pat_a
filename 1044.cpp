#include <cstdio>
const int maxn = 100005;
int sum[maxn];
int nearm = 0x7fffffff;
int upper_bound(int L, int R, int key) {	//����[L,R)�����ڵ�һ������key��λ��
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
		sum[i] += sum[i - 1];   //sum[i]Ϊ�ӵ�1������i��Ԫ��֮��
	}
	for (int i = 1; i <= n; i++) {
		int j = upper_bound(i, n + 1, sum[i - 1] + m);	//���Ҷ˵�(������key��Խ��һ����������������ڵĵ�һ��)
		if (sum[j - 1] - sum[i - 1] == m) {//Խ��һ������Ҫj-1
			nearm = m;
			break;
		}
		else if (j <= n && sum[j] - sum[i - 1] < nearm) {//�ҳ����m��ֵnearm
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