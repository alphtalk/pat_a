#include <cstdio>
#include <cstring>
int main(){
	char s1[1005], s2[1005];
	int c[150] = {0};
	gets(s1);
	gets(s2);
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	//记录每个颜色需要多少个，下标代表颜色
	for(int i = 0; i < len2; i++)	c[s2[i]]++;
	//遍历买到的串，每碰到一个如果正好是需要的(不为0)，就减少一个
	for(int i = 0; i < len1; i++)
		if(c[s1[i]] != 0)	c[s1[i]]--;

	int count = 0;
	for(int i = 0; i < 150; i++)//统计还有多少需要的
		if(c[i] != 0)	count += c[i] ;
	
	if(count == 0)	//说明没缺失
		printf("Yes %d", len1 - len2);
	else printf("No %d", count);

	return 0;
}