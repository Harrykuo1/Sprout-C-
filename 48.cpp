//  https://neoj.sprout.tw/problem/48/
#include<stdio.h>
#include<algorithm>
using namespace std;
int now=0;
int fronts[2005],mid[2005];
void dfs(int left,int right){
    int i;
    if(left>right){
        return;
    }
    for(i=left;i<=right;i++){
        if(mid[i]==fronts[now]){
            break;
        }
    }
    now++;
    dfs(left,i-1);
    dfs(i+1,right);
    printf("%d\n",mid[i]);
}
int main(){
    int length=0;
    while(scanf("%d",&fronts[length])!=EOF){
        mid[length]=fronts[length];
        length++;
    }
    sort(mid,mid+length);
    length--;
    dfs(0,length);
}
