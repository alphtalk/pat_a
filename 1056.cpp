//ԭ������������������25�ǵ�6����18�ǵ�0����0�ǵ�8������������������֪�����ȵ�����19���ٵ�0��25���ٵ�8��57.
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
		if (temp % NG == 0) group = temp / NG;   //ȷ����Ϊ����
		else group = temp / NG + 1;
		for (int i = 0; i < group; i++) {
			int k = q.front();
			for (int j = 0; j < NG; j++) {
				if (i * NG + j >= temp) break;	//��һ��ִ�е����һ���j�������һ����ʱ������ȥ
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