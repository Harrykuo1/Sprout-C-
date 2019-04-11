//  https://neoj.sprout.tw/problem/63/
#include<stdio.h>
int ans[6],ary[20],ctrl;
void dfs(int now,int limit,int use){
	if(now==6){

		printf("%d",ans[0]);
		for(int i=1;i<6;i++){
			printf(" %d",ans[i]);
		}
		printf("\n");
		ctrl=1;
		return;
	}
	for(int i=use;i<limit;i++){
			ans[now]=ary[i];
			dfs(now+1,limit,i+1);
	}
}
int main(){
	int n;
	ctrl=0;
	while(scanf("%d",&n)!=EOF){
		if(n==0){
			break;
		}
		if(ctrl){
			printf("\n");
		}
		for(int i=0;i<n;i++){
			scanf("%d",&ary[i]);
		}
		dfs(0,n,0);
	}
}
