// https://neoj.sprout.tw/problem/19/
#include<stdio.h>
int main(){
	int a,n,times,up;
	scanf("%d",&times);
	for(int o=0;o<times;o++){
		int stack[100005]={0},ary[100005];
		a=1;up=1;
		scanf("%d",&n);
		for(int p=0;p<n;p++){
			scanf("%d",&ary[p]);
		}
		int ctrl=1;
		for(int i=0;i<n;i++){
			if(ary[i]!=stack[up-1]&&a==n+1){
				printf("No\n");
				ctrl=0;
				break;
			}
			if(a==ary[i]){
				a++;
			}
			else if(up>0&&ary[i]==stack[up-1]){
				up--;
			}
			else{
				stack[up]=a;
				a++;
				up++;
				i--;
			}
		}
		if(ctrl){
			printf("Yes\n");
		}
	}
}
