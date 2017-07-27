/*
1、首先将元素以string为个体存放，二位数组开不了，太大
2、按字典序比较是容易想到的方法
3、比较string用sort重写比较函数，而不是for循环
4、比较目的是组成最小数，领会a+b<b+a的比较函数写法
5、消到只剩一个首元素还为0则不用消了，所以条件为>1,看到网上各种题解非得消到0，再去另外判断，真是天下题解一大抄，学而不思，切忌！
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 10005;
string str[maxn];
bool cmp(string a, string b) {
	return a + b < b + a;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	sort(str, str + n, cmp);
	string ans;
	for (int i = 0; i < n; i++)
		ans += str[i];
	while (ans.size() > 1 && ans[0] == '0')//若字符串大于1且首元素为0则消除，消到只剩一个首元素还为0则不用消了
		ans.erase(ans.begin());			//消除第一个元素
	cout << ans;

	return 0;
}