#include <iostream>
#include <vector>
using namespace std;
char space[1000][1000]={{0}};
int main(){
    string s;
    int n;
    cin>>s>>n;
    int len=s.size();
    int col=0;
    int cnt=0;
    while(cnt<len){
        for(int i=0;i<n;i++){
            if(cnt==len){
                break;
            }
            space[i][col]=s[cnt++];
        }
        col++;
        if(cnt==len){
            break;
        }
        for(int i=n-1;i>=0;i--){
            if(cnt==len){
                break;
            }
            space[i][col]=s[cnt++];
        }
        col++;
    }
    cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<col;j++){
            if(cnt==len){
                return 0;
            }
            if(space[i][j]==0){
                break;
            }
            cout<<space[i][j];
            cnt++;
        }
        cout<<endl;
    }
    return 0;
}