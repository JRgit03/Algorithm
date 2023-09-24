#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n,m; 
int st[N];
int ans[N];
int u[N],v[N];
vector<int> g[N];
vector<int> h[N];

void dfs2(int u){
    if(ans[u] != -1) return;
    ans[u] = 1;
    
    for(auto v : g[u])
        dfs2(v);
}

void dfs(int u,int val){
    
}

int main(){
    cin>>n>>m;
    memset(ans,-1,sizeof ans);
    for(int i=2;i<=n;i++) {
        int x; cin>>x;
        g[i].push_back(x);
    }
    vector<int> vec;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i];
        if(u[i] == 1 || v[i] == 1){
            if(u[i] == 1) vec.push_back(v[i]);
            else vec.push_back(u[i]);
        }
        h[u[i]].push_back(v[i]);
        h[v[i]].push_back(u[i]);
    }    
    for(auto &st : vec)
        dfs2(st);

    for(int i=1;i<=m;i++){
        if(ans[u[i]] && ans[v[i]]){
            
        }
    }

    return 0;
}