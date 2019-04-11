// //https://neoj.sprout.tw/problem/36/
#include<stdio.h>
int main(){
	int n,ary[100001],upper=-1,a;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		if(a==1){
			scanf("%d",&a);
			upper++;
			ary[upper]=a;
		}
		else{
			if(upper==-1){
				printf("empty!\n");
			}
			else{
				printf("%d\n",ary[upper]);
				upper--;
			}
		}
	}
} 
