//  https://neoj.sprout.tw/problem/78/
#include<stdio.h>
#include<string.h>
using namespace std;
int ary[7];
bool check(){
	if(ary[1]==ary[2]&&ary[2]==ary[3]&&ary[3]==ary[4]&&ary[4]==ary[5]&&ary[5]==ary[6]&&ary[6]==0){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	while(~scanf("%d%d%d%d%d%d",&ary[1],&ary[2],&ary[3],&ary[4],&ary[5],&ary[6])){
		if(check()){
			break;
		}
		int can[7];
		int sum=ary[6];
		sum+=ary[5];
		can[1]=ary[5]*11;
		ary[1]>can[1]?(ary[1]-=can[1],can[1]=0):(can[1]-=ary[1],ary[1]=0);
		sum+=ary[4];
		can[2]=ary[4]*5;
		sum+=ary[3]/4;
		switch(ary[3]%4){
			case 1:
				can[1]+=7;
				can[2]+=5;
				sum+=1;
				break;
			case 2:
				can[1]+=6;
				can[2]+=3;
				sum+=1;
				break;
			case 3:
				can[1]+=5;
				can[2]+=1;
				sum+=1;
				break;
			default:
				break;
		}
		if(ary[2]>can[2]){
			ary[2]-=can[2];
			sum+=ary[2]/9;
			if(ary[2]%9!=0){
				sum+=1;
				can[1]+=(9-(ary[2]%9))*4;
			}
		}
		else if(ary[2]!=can[2]){
			can[2]-=ary[2];
			can[1]+=can[2]*4;
		}
		if(ary[1]>can[1]){
			ary[1]-=can[1];
			sum+=ary[1]/36;
			if(ary[1]%36!=0){
				sum++;
			}
		}
		printf("%d\n",sum);
	}
}
