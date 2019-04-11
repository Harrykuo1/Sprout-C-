//  https://neoj.sprout.tw/problem/21/
#include<cstdio>
struct car{
	int front;
	int back;
};
int main(){
	int n;
	scanf("%d",&n);
	car ary[100005];
	ary[0].back=1;
	for(int i=1;i<=n;i++){
		ary[i].front=i-1;
		ary[i].back=i+1;
	}	
	int times,a,b;
	scanf("%d",&times);
	while(times--){
		scanf("%d%d",&a,&b);
		if(a==0){
			ary[ary[b].front].back=ary[b].back;
			ary[ary[b].back].front=ary[b].front;
		}
		else{
			if(b!=ary[0].back){
				int change[4];
				change[0]=ary[ary[b].front].front;
				change[1]=ary[b].front;
				change[2]=b;
				change[3]=ary[b].back;
				ary[change[0]].back=change[2];
				ary[change[2]].front=change[0];
				ary[change[2]].back=change[1];
				ary[change[1]].front=change[2];
				ary[change[1]].back=change[3];
				ary[change[3]].front=change[1];	
			}
		}
	}
	int out=ary[0].back;
	printf("%d",out);
	out=ary[out].back;
	while(out!=n+1){
		printf(" %d",out);
		out=ary[out].back;
	}
	printf("\n");
} 
