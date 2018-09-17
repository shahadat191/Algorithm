
//  Created by Shahadat Hossain on 9/17/18.
//  Copyright © 2018 Shahadat Hossain. All rights reserved.
//

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


int rcap[110][110];
int n;
int parent[110], visit[110], cost[110];
int bfs(int start, int dest){
    queue<int> sq;
    sq.push(start);
    parent[start] = start;
    cost[start] = 1000000009;
    
    while (!sq.empty()) {
        int temp = sq.front();
        visit[temp] = 1;
        sq.pop();
        
        if(temp == dest){
            while(parent[temp] != temp){
                rcap[parent[temp]][temp] -= cost[dest];
                rcap[temp][parent[temp]] += cost[dest];
                temp = parent[temp];
            }
            return cost[dest];
        }
        
        for(int i = 1; i<=n; i++){
            if(rcap[temp][i] > 0 && !visit[i]){
                cost[i] = min(cost[temp], rcap[temp][i]);
                parent[i] = temp;
                sq.push(i);
            }
        }
    }
    return 0;
}

int main(){
    int t, cas = 1;
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d", &n);
        memset(rcap, 0, sizeof(rcap));
        memset(visit, 0, sizeof(visit));
        
        int src, dest, c;
        scanf("%d %d %d", &src, &dest, &c);
        
        for(int i = 0; i<c; i++){
            int uu,vv, cost;
            scanf("%d %d %d", &uu, &vv, &cost);
            rcap[uu][vv] += cost;
            rcap[vv][uu] += cost;
        }
        
        ll mxflow = 0;
        int temp = bfs(src,dest);
        
        while (temp>0) {
            memset(visit, 0, sizeof(visit));
            mxflow += temp;
            temp = bfs(src, dest);
        }
        printf("Case %d: %lld\n", cas++, mxflow);
        
    }
}