//  https://neoj.sprout.tw/problem/59/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a;
	scanf("%d",&n);
		priority_queue<int ,vector<int>,greater<int>>ary;
		while(n--){
			scanf("%d",&a);
			if(a==1){
				scanf("%d",&a);
				ary.push(a);
			}
			else{
				if(ary.empty()){
					printf("empty!\n");
				}
				else{
					printf("%d\n",ary.top());
					ary.pop();
				}				
			}
		}
	
}
