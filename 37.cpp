// //https://neoj.sprout.tw/problem/19/
#include<stdio.h>
int main(){
	int n,ary[100001],upper=0,lower=0,a;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		if(a==1){
			scanf("%d",&a);
			ary[upper]=a;
			upper++;
		}
		else{
			if(upper==lower){
				printf("empty!\n");
			}
			else{
				printf("%d\n",ary[lower]);
				lower++;
			}
		}
	}
} 
