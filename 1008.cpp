#include<cstdio>
int main(){
	int N,floor_,temp=0,sum=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&floor_);     			
		if((floor_-temp)>=0)			//每次如果上升的话目标楼层floor减去目前所在的楼层temp
			sum+=(floor_-temp)*6+5;
		else sum+=(temp-floor_)*4+5;	//如果下降目前的楼层temp减去目标楼层floor
		temp=floor_;					//将目前的楼层置为已到达的目标楼层
	}
	printf("%d",sum);
	return 0;
}