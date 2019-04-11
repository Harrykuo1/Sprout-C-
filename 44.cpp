//  https://neoj.sprout.tw/problem/44/
#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
struct position{
    int x,y,times;
};
int vx[]={0,0,-1,1},vy[]={1,-1,0,0};
int main(){
	int n;
	while(scanf("%d",&n)!=EOF && n > 0){
		char mp[105][105];
		int cx,cy;
		for(int p=0;p<n;p++){
			char input[105];
			scanf("%s",input);
			int xlimit=strlen(input);
			for(int i=0;i<xlimit;i++){
				mp[p][i]=input[i];
				if(mp[p][i]=='K'){
					cx=i;
					cy=p;
				}
			}
		}
		queue<position>ary;
		mp[cy][cx]='#';
		ary.push((position){cx,cy,0});
		bool ctrl=true;
		while(!ary.empty()){
			int x=ary.front().x;
			int y=ary.front().y;
			if(mp[y][x]=='@'){
				ctrl=false;
				printf("%d\n",ary.front().times);
				break;
			}
			for(int p=0;p<4;p++){
				if(mp[y+vy[p]][x+vx[p]]=='.'||mp[y+vy[p]][x+vx[p]]=='@'){
					if(mp[y+vy[p]][x+vx[p]]=='.'){
						mp[y+vy[p]][x+vx[p]]='#';
					}
					ary.push((position){x+vx[p],y+vy[p],ary.front().times+1});
				}
			}
			ary.pop();
		}
		if(ctrl){
			printf("= =\"\n");
		}
	}
}
