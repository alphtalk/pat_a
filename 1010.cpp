#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
LL Map[256];
LL inf=(1LL << 63)-1;		//表示long long最大值2^63-1，编译器可能会提醒忽略即可
void init(){
	for(char c='0';c<='9';c++){
		Map[c]=c-'0';
	}
	for(char c='a';c<='z';c++){
		Map[c]=c-'a'+10;
	}
}
LL convertNum10(char a[],LL radix,LL t){//转换成10进制
	LL ans=0;
	int len=strlen(a);
	for(int i=0;i<len;i++){
		ans=ans*radix+Map[a[i]];
		if(ans<0||ans>t)			//题目没有说的是再超过long long的取值范围则为impossible
			return -1;
	}	
	return ans;
}
int cmp(char N2[],LL radix,LL t){
	int len=strlen(N2);
	LL num=convertNum10(N2,radix,t);
	if(num<0)	return 1;
	if(t>num)	return -1;
	else if(t==num)	return 0;
	else return 1;
}
LL binarySearch(char N2[],LL left,LL right,LL t){//二分查找
	LL mid;
	while(left<=right){
		mid=(left+right)/2;
		int flag=cmp(N2,mid,t);
		if(flag==0)	return mid;
		else if(flag==-1)	left=mid+1;
		else right=mid-1;
	}
	return -1;
}
int findLargestDigit(char N2[]){//求最大的数位
	int ans=-1,len=strlen(N2);
	for(int i=0;i<len;i++){
		if(Map[N2[i]]>ans)
			ans=Map[N2[i]];
	}
	return ans+1;		//进制最小是ans+1,比如一个数中出现了8这个数字，则这个数最小是9进制的
}
char N1[20],N2[20],temp[20];
int tag,radix;

int main(){
	init();
	scanf("%s%s%d%d",N1,N2,&tag,&radix);  //21 e 1 5   4-25
	if(tag==2){					//如果tag==2的话,交换N1和N2
		strcpy(temp,N1);
		strcpy(N1,N2);
		strcpy(N2,temp);
	}
	LL t=convertNum10(N1,radix,inf);//将N1从radix进制转化为10进制
	LL low=findLargestDigit(N2);	//找到N2中最大的数位加一，当做二分下界
	printf("low%d",low);
	LL high=max(low,t);			
	//LL high=low>t?low:t;	
	printf("%d",high);
	/*上界：这里要注意或者是low+1进制比如16 10 1 10最大是16进制当然也可以是17进制,
	但是我们要取满足条件的最小进制,或者是t+1进制比如11 b 1 10最大是12进制*/
	LL ans=binarySearch(N2,low,high,t);
	if(ans==-1)	printf("Impossible");
	else printf("%lld",ans);
	return 0;
} 
