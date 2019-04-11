//  https://neoj.sprout.tw/problem/42/
#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
struct position
{
	int x;
	int y;
 	char word;
};
int xv[]={0,0,-1,1},yv[]={1,-1,0,0};
position mp[1005][1005];
int main()
{
	int xlimit,ylimit,times;
	scanf("%d",&times);
	while(times--){
		int sum=0;
		scanf("%d%d",&ylimit,&xlimit);
		for(int j=0;j<ylimit;j++){
			char input[1005];
			scanf("%s",input);
			for(int i=0;i<xlimit;i++){
				mp[j][i].x=i;
				mp[j][i].y=j;
				mp[j][i].word=input[i];
			}
		}
		for(int j=0;j<ylimit;j++){
			for(int i=0;i<xlimit;i++){
				if(mp[j][i].word=='.'){
					sum++;
					queue<position>ary;
					mp[j][i].word='#';
					ary.push(mp[j][i]);
					while(!ary.empty()){
						int x=ary.front().x;
						int y=ary.front().y;
						for(int p=0;p<4;p++){
							if(((x+xv[p]>=0)&&(x+xv[p]<xlimit))&&((y+yv[p]>=0)&&(y+yv[p]<ylimit))&&(mp[y+yv[p]][x+xv[p]].word=='.')){
								mp[y+yv[p]][x+xv[p]].word='#';
								ary.push(mp[y+yv[p]][x+xv[p]]);
							}
						}
						ary.pop();
					}
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
