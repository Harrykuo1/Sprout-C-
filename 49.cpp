//  https://neoj.sprout.tw/problem/49/
#include<cstdio>
#include<vector>
using namespace std;
int big,searchs[100005];
vector<int> ary[100005];
void dfs(int now){
    big++;
    int length=ary[now].size();
    if(ary[now].empty()){
        return ;
    }
    for(int i=0;i<length;i++){
        if(searchs[ary[now][i]]!=0){
            big+=searchs[ary[now][i]];
            continue;
        }
        else{
            dfs(ary[now][i]);
        }
    }

}
int main(){
	int times;
	scanf("%d",&times);
	while(times--){
        big=0;
		int num,timess;
		scanf("%d%d",&num,&timess);
		for(int i=0;i<=num+1;i++){
            ary[i].clear();
            searchs[i]=0;
        }
		while(timess--){
			int a,b;
			scanf("%d%d",&a,&b);
			ary[a].push_back(b);
		}
		scanf("%d",&timess);
		for(int i=1;i<=num;i++){
            big=0;
            dfs(i);
            searchs[i]=big;
		}
		while(timess--){
            int a;
            scanf("%d",&a);
            printf("%d\n",searchs[a]);
		}
	}
}
