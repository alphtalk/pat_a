//原本对样例的理解理解是25是第6个，18是第0个，0是第8个这样，，看解析才知道是先第六个19，再第0个25，再第8个57.
#include <cstdio>
#include <queue>
using namespace std;
struct Mice {
	int weight;
	int rank;
}mices[1005];

int main() {
	int NP, NG, order;
	scanf("%d%d", &NP, &NG);
	for (int i = 0; i < NP; i++) {
		scanf("%d", &mices[i].weight);
	}
	queue<int> q;
	for (int i = 0; i < NP; i++) {
		scanf("%d", &order);
		q.push(order);
	}
	int temp = NP, group;
	while (q.size() != 1) {
		if (temp % NG == 0) group = temp / NG;   //确定分为几组
		else group = temp / NG + 1;
		for (int i = 0; i < group; i++) {
			int k = q.front();
			for (int j = 0; j < NG; j++) {
				if (i * NG + j >= temp) break;	//这一句执行到最后一组第j个（最后一个）时，跳出去
				int front = q.front();
				printf("front=%d k=%d   ", front,k);
				if (mices[front].weight > mices[k].weight) {
					k = front;
				}
				mices[front].rank = group + 1;
				printf("front=%d k=%d %d %d\n", front,k,mices[front].weight,mices[k].weight);
				q.pop();
			}
			q.push(k);
		}
		temp = group;
	}
	mices[q.front()].rank = 1;
	for (int i = 0; i < NP; i++) {
		printf("%d", mices[i].rank);
		if (i < NP - 1) printf(" ");
	}
	return 0;
}