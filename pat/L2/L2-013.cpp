#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n,m;

bool vis[N] , st[N];
vector<int> h[N];

void dfs(int u){
    vis[u] = true;

    for(auto v : h[u])
        if(!vis[v] && !st[v]) 
           dfs(v);
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        h[a].push_back(b);
        h[b].push_back(a);
    }
    int k;cin>>k;
    int del = 0 , cnt = 0;

    for(int i=0;i<n;i++)
        if(!vis[i] && !st[i])
        {
            dfs(i);++cnt;
        }

    for(int i=0;i<k;i++){
        memset(vis,false,sizeof vis);
        
        int att;cin>>att;
        ++del;st[att] = true;
       
        int block = 0 , f = false;
        for(int i=0;i<n;i++)
            if(!vis[i] && !st[i])
            {
               dfs(i);block++;
            }

        if(cnt == block + 1 || cnt==block) {
            printf("City %d is lost.\n",att);
        }else {
            printf("Red Alert: City %d is lost!\n",att);
        }
        if(del==n){
            printf("Game Over.\n");return 0;
        }

        cnt = block;
    }
    return 0;
}