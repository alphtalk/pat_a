/*
��������һ������ʱ����ʵ�Ƿֶ���ģ�
��ǧ���ټ�ʮ���ڣ���ǧ���ټ�ʮ���򣬼�ǧ���ټ�ʮ��
����λ����Կ������ĸ���Ϊһ����λ�����������4λ��Ϊ���Σ���һ�κ�� ��
��������ڰ�λ��Ϊ���Σ���һ�κ�� �ڣ��ڶ��κ�� ��
��left��right����ָ��������ÿ����ô���
*/
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string d[10] = { "ling", "yi", "er", "san", "si", "wu", "liu","qi", "ba", "jiu" };
string j[5] = { "Shi", "Bai", "Qian", "Wan", "Yi", };
int main() {
	char in[15];
	gets(in);
	int len = strlen(in);
	int left = 0, right = len - 1;//leftĬ��Ϊ������0��ʼ��rightĬ��ָ�����һλ
	int i = 0;
	if (in[0] == '-') {	//����Ǹ�����left��1��ʼ�������0��ʼ
		cout << "Fu";
		left++;
	}
	//��Ϊ��ʮ��ǧʦ���ұ߿�ʼ����������Ҫ���ұ߿�ʼÿ�θ�4λ���ֶ�
	while (left + 4 <= right)	right -= 4;//left��rightָ���һ�ε���β
	while (left < len) {		//ѭ������ÿһ��
		bool flag = false;		//û���ۼƵ�0
		bool isPrint = false;	//�ö��Ƿ����������
		while (left <= right) {	//����һ�ε�ÿһλ
			if (left > 0 && in[left] == '0') {//�����ǰΪ0�����������һ��
				flag = true;
			}
			else {				//�����ǰ��Ϊ0
				if (flag == true) {	//�����ۼƵ�0,�������һ��0
					printf(" ling");
					flag = false;
				}
				if (left > 0) printf(" ");//������λ�����ǰ�ӿո�
				cout << d[in[left] - '0'];	//�����ǰ����
				isPrint = true;			//�趨Ϊ���������
				if (left != right) {	//ÿ�����ֳ��˸�λ�⣬���ڵڼ�λ�ֱ����ǧ��ʮ
					cout << " " << j[right - left - 1];
				}
			}
			left++;
		}
		if (isPrint == true && right != len - 1) {//���Ǹ�λ������������
			cout << " " << j[(len - 1 - right) / 4 + 2];
		}
		right += 4;	//�����һ��
	}
	return 0;
}