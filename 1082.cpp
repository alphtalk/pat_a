/*
当我们念一个数的时候，其实是分段念的：
几千几百几十几亿，几千几百几十几万，几千几百几十几
从这段话可以看出，四个数为一个单位，若输入大于4位则为两段，第一段后加 万
若输入大于八位则为三段，第一段后加 亿，第二段后加 万
用left和right两个指针来处理每段怎么输出
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
	int left = 0, right = len - 1;//left默认为正数从0开始，right默认指向最后一位
	int i = 0;
	if (in[0] == '-') {	//如果是负数，left从1开始，否则从0开始
		cout << "Fu";
		left++;
	}
	//因为个十百千师从右边开始，所以我们要从右边开始每次割4位来分段
	while (left + 4 <= right)	right -= 4;//left，right指向第一段的首尾
	while (left < len) {		//循环处理每一段
		bool flag = false;		//没有累计的0
		bool isPrint = false;	//该段是否输出过数字
		while (left <= right) {	//处理一段的每一位
			if (left > 0 && in[left] == '0') {//如果当前为0，则继续看下一个
				flag = true;
			}
			else {				//如果当前不为0
				if (flag == true) {	//且有累计的0,则先输出一个0
					printf(" ling");
					flag = false;
				}
				if (left > 0) printf(" ");//不是首位，输出前加空格
				cout << d[in[left] - '0'];	//输出当前数字
				isPrint = true;			//设定为输出过数字
				if (left != right) {	//每个数字除了个位外，视在第几位分别输出千百十
					cout << " " << j[right - left - 1];
				}
			}
			left++;
		}
		if (isPrint == true && right != len - 1) {//不是个位，输出万或者亿
			cout << " " << j[(len - 1 - right) / 4 + 2];
		}
		right += 4;	//输出下一节
	}
	return 0;
}