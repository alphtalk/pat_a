/*
1�����Ƚ�Ԫ����stringΪ�����ţ���λ���鿪���ˣ�̫��
2�����ֵ���Ƚ��������뵽�ķ���
3���Ƚ�string��sort��д�ȽϺ�����������forѭ��
4���Ƚ�Ŀ���������С�������a+b<b+a�ıȽϺ���д��
5������ֻʣһ����Ԫ�ػ�Ϊ0�������ˣ���������Ϊ>1,�������ϸ������ǵ�����0����ȥ�����жϣ������������һ�󳭣�ѧ����˼���мɣ�
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
	while (ans.size() > 1 && ans[0] == '0')//���ַ�������1����Ԫ��Ϊ0������������ֻʣһ����Ԫ�ػ�Ϊ0��������
		ans.erase(ans.begin());			   //������һ��Ԫ��
	cout << ans;

	return 0;
}