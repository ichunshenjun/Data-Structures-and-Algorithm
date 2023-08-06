#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
int n,m;
struct node{
    int val;
    int cnt;
};
queue<node> tmp;
priority_queue<node>q;
bool operator <(const node a,const node b){
    return a.val<b.val;
}
int main(){
    scanf("%d %d",&n,&m);
	node a;
	for(int i=1,rest;i<=m;++i){
        scanf("%d %d",&a.cnt,&a.val);
		q.push(a);
		rest=n;// rest为输出某一字符后，剩余的长度，初始为n 
		while(rest>0){
            if(q.empty())
                break;
            a=q.top();
            q.pop();
            for(int j=1;j<=min(rest,a.cnt);j++){
                printf("%d",a.val);
            }
            tmp.push(a);
            rest-=a.cnt;
        }
        while(!tmp.empty()){
            q.push(tmp.front());
            tmp.pop();
        }
        printf("\n");
    }
    return 0;
}