//  https://neoj.sprout.tw/problem/47/
#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;
int input_times,x;
char str[50];
std::multiset<int>seta,setb;
std::multiset<int>::iterator a,b;
int main(){
    scanf("%d",&input_times);
    while(input_times--){
        scanf("%s %d",&str,&x);
        if(str[0]=='i'){
            seta.insert(x);
            setb.insert(-x);
        }
        else if(str[0]=='d'){
            seta.erase(x);
            setb.erase(-x);
        }
        else{
            if(seta.count(x)){
                printf("%d\n", x);
                continue;
            }
                a=seta.lower_bound(x);
                b=setb.lower_bound(-x);
            if(abs(*a-x)==abs(*b-(-x)))
                printf("%d %d\n",min(*a,-(*b)),max(*a,-(*b)));
            else if( abs(*a-x)<abs(*b-(-x)))
                printf("%d\n",*a);
            else
                printf("%d\n",-(*b));
        }
    }
}
