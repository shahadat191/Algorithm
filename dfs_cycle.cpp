/*
 Shahadat Hossain
 I.C.T Department
 Comilla University
 Session: 2013-2014
*/
 
#include<iostream>
#define ms(a,b) memset(a, b, sizeof(a));
using namespace std;
 
int n;
int num[110][110];
int visit[110];
int parent[110];
int res[110];
bool flag;
int last, start;
 
void dfs(int temp){
    visit[temp]=1;
    for(int i=1 ; i<=n; i++){
        if(num[temp][i] == 0 || i == temp)
            continue;
 
        if(visit[i] == 0){
            parent[i] = temp;
            dfs(i);
        }
        else if(visit[i] == 1){
            flag = true;
            last = temp;
            start = i;
        }
    }
    visit[temp] = 2;
}
void clear(){
    ms(num, 0);
    ms(visit, 0);
    ms(parent, 0);
    ms(res,0);
    flag = false;
}
 
int main(){
    int t;
    cin>>t;
    while (t--) {
        clear();
        cin>>n;
        int m;
        cin>>m;
 
        for(int i=1; i<=m; i++){
            int x,y;
            cin>>x>>y;
            num[x][y] = 1;
        }
        for(int i = 1; i<=n; i++){
            if(visit[i] == 0){
                dfs(i);
            }
            if(flag)
                break;
        }
        if(flag){
            while (last != start) {
                res[last] = 1;
                last = parent[last];
            }
            res[start] = 1;
            for(int i = 1; i<=n; i++){
                if(res[i] == 1)
                    cout<<i<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
}
