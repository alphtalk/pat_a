#include<cstdio>
#include<map>
using namespace std;
int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	map<int, int> ma;
	int temp;
	for (int i = 0; i<n*m; i++) {		
			scanf("%d", &temp);
			if (ma.find(temp) != ma.end()) {
				ma[temp]++;
			}
			else ma[temp] = 1;
	}
	int k = 0, max = 0;
	for (map<int, int>::iterator it = ma.begin(); it != ma.end(); it++) {
		if (it->second > max) {
			k = it->first;
			max = it->second;
		}
	}
	printf("%d",k);
	return 0;
}