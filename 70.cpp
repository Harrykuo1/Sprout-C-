//  https://neoj.sprout.tw/problem/70/
#include<stdio.h>
#include<queue>
#include<iostream>
using namespace std;
int main(){
	int n;
	while(~scanf("%d",&n) && n>0){
		std::priority_queue<unsigned long long int,vector<unsigned long long int>,greater<unsigned long long int> > ary;
		int input;
		for(int i=0;i<n;i++){
			scanf("%d",&input);
			ary.push(input);
		}
		unsigned long long int sum=0;
		while(ary.size()>1){
			unsigned long long int a=ary.top();
			ary.pop();
			a+=ary.top();
			sum+=a;
			ary.pop();
			ary.push(a);
		}
		printf("%llu\n",sum);
	}
}
