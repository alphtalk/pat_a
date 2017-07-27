/*最初版本

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 1000005;
long long a[maxn], b[maxn];
int main() {
	int n1, n2;
	vector<long long> v;
	scanf("%d", &n1);
	for (int i = 0; i < n1; i++) {
		scanf("%lld", &a[i]);
	}
	scanf("%d", &n2);
	for (int i = 0; i < n2; i++) {
		scanf("%lld", &b[i]);
	}
	int j = 0, k = 0;
	while (j < n1 && k < n2) {
		if (a[j] <= b[k]) {
			v.push_back(a[j++]);
		}
		else {
			v.push_back(b[k++]);
		}
	}
	
	if (j != n1) {
		for (int i = j; i < n1; i++) {
			v.push_back(a[i]);
		}
	}
	if (k != n2) {
		for (int i = k; i < n2; i++) {
			v.push_back(b[i]);
		}
	}
	printf("%d", v[(v.size() - 1) / 2]);
	return 0;
}
*/


/*
优化1：

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 1000005;
long long a[maxn], b[maxn];
int main() {
	int n1, n2;
	vector<long long> v;
	scanf("%d", &n1);
	for (int i = 0; i < n1; i++) {
		scanf("%lld", &a[i]);
	}
	scanf("%d", &n2);
	for (int i = 0; i < n2; i++) {
		scanf("%lld", &b[i]);
	}
	int j = 0, k = 0;
	while (j < n1 && k < n2) {
		if (a[j] <= b[k]) {
			v.push_back(a[j++]);
		}
		else {
			v.push_back(b[k++]);
		}
	}
	while (j < n1) v.push_back(a[j++]);
    while (k < n2) v.push_back(b[k++]);
	printf("%d", v[(v.size() - 1) / 2]);
	return 0;
}
*/

/*
优化2

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int INF = 0x7fffffff;
const int maxn = 1000005;
long long a[maxn], b[maxn];
int main() {
	int n1, n2;
	vector<long long> v;
	scanf("%d", &n1);
	for (int i = 0; i < n1; i++) {
		scanf("%lld", &a[i]);
	}
	scanf("%d", &n2);
	for (int i = 0; i < n2; i++) {
		scanf("%lld", &b[i]);
	}
	a[n1] = b[n2] = INF;		//防止越界
	int j = 0, k = 0, count = 0;
	int median = (n1 + n2 - 1) / 2;
	while (count < median) {
		if (a[j] < b[k])	j++;
		else k++;
		count++;
	}
	if (a[j] < b[k]) {
		printf("%d", a[j]);
	}
	else {
		printf("%d", b[k]);
	}
	return 0;
}
*/

/*优化3*/

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 1000005;
long long a[maxn], b[maxn];
int main() {
	int n1, n2;
	vector<long long> v;
	long long temp;
	scanf("%d", &n1);
	for (int i = 0; i < n1; i++) {
		scanf("%lld", &temp);
		v.push_back(temp);
	}
	scanf("%d", &n2);
	for (int i = 0; i < n2; i++) {
		scanf("%lld", &temp);
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	printf("%d", v[(v.size() - 1) / 2]);
	return 0;
}