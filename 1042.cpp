#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
	int N,shuff[54];
	string s1[54]={
		"S1", "S2", "S3", "S4","S5", "S6","S7", "S8","S9", "S10","S11", "S12","S13",
		"H1", "H2", "H3", "H4","H5", "H6","H7", "H8","H9", "H10","H11", "H12","H13",
		"C1", "C2", "C3", "C4","C5", "C6","C7", "C8","C9", "C10","C11", "C12","C13",
		"D1", "D2", "D3", "D4","D5", "D6","D7", "D8","D9", "D10","D11", "D12","D13",
		"J1","J2"
	},s2[54];
	scanf("%d", &N);
	for(int i=0;i<54;i++)
		scanf("%d", &shuff[i]);
	for(int i=0;i<N;i++){
		for(int j=0;j<54;j++)
		s2[shuff[j]-1]=s1[j];
		for(int j=0;j<54;j++)
			s1[j]=s2[j];		//将每一次结果保存于s1以便下一次再进行移动
	}
	for(int i=0;i<54;i++){
		if(i!=0)	putchar(' ');
		cout<<s2[i];
	}	
	return 0;
}
/*
这题题意是挨个将坐标位置的字符串放到输入数字所表示的位置.
不难想到用两个数组来做一个交接，每次将结果放到s1中，需要注意的是
输入是从1开始的，所以赋值的时候要减去1.
 */