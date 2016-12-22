/*
这道题的题意是先给定一个数N，随后输入N个数代表一个圆上相邻两点之间的距离，然后
让你计算任意两点之间的最短距离（你需要考虑的是顺时针最短还是逆时针最短），这里
原本做的是知道哪两个点用循环的方式加起来最后超时了，后来想到先计算出每个点到某
个固定点（比如1这个点）的距离，最后算两个点的距离时直接将这两个点到1这个点的距
离相减即可，本题假设点的位置顺时针方向递增。
 */
#include <cstdio>
int main(){
	int N, M, a[100005] = {0},counterclockwise, clockwise, sum = 0, pair[10005][2];
	scanf("%d", &N);
	int temp = 0;
	for(int i = 1; i <= N; i++){
		scanf("%d", &temp);
		sum += temp;			//圆周长
		a[i+1] = a[i] + temp;
	}
	scanf("%d", &M);
	for(int i = 0; i < M; i++){
		clockwise = counterclockwise = 0;
		scanf("%d%d", &pair[i][0], &pair[i][1]);
		int min = pair[i][0] > pair[i][1] ? pair[i][1] : pair[i][0];
		int max = pair[i][0] < pair[i][1] ? pair[i][1] : pair[i][0];
		clockwise = a[max] - a[min];		//两个点的顺时针方向距离
		counterclockwise = sum - clockwise; //逆时针方向距离
		printf("%d\n", clockwise < counterclockwise ? clockwise : counterclockwise);
	
	}
	return 0;
}
