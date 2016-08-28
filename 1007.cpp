#include<cstdio>
int main(){

	int N,F,L,maximum=0;
	int digital[10005];
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",digital[i]);
		if(maximum>(maximum+digital[i])){
			L=i;
		}
	}
	return 0;
}