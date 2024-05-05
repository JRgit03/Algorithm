#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

#ifdef LOCAL
#include "../../../algorithm-template/debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e5 + 10;
int n,l,r;
string s;
int ans[N],sz[N];
vector<int> g[N];

int depth[N];
void dfs_depth(int u){
    for(auto v : g[u]){
        if(depth[v]) continue;
        depth[v] = depth[u] + 1;
        dfs_depth(v);
    }
}

int vis[N];
vector<int> path;
void dfs_(int u){
    for(auto v : g[u]){
        if(depth[v] > depth[u] && !vis[v]){
            vis[v] = 1;
            path.push_back(v);
            dfs_(v);
        }
    }
}

void dfs(int u,int f){
    if(s[u] == 'W') sz[u] = 1;
    for(auto v : g[u]){
        if(v == f) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
    debug(u, sz[u]); 
    if(s[u] == 'R'){
        sz[u] += 1, vis[u] = 1;
        path.push_back(u);
        dfs_(u);
        for(int i = (path.size() & 1); i < path.size(); i++) ans[path[i]] = (i & 1 ? 1 : -1);
        path.clear(), sz[u] = 0;
    }else if(u == 1 && s[u] == 'W'){
        vis[u] = 1, path.push_back(u); 
        dfs_(u);
        for(int i = 0; i < path.size(); i++) ans[path[i]] = 1;
        path.clear(), sz[u] = 0;
    }
}

void solve(){
    cin>>n>>l>>r;
    cin>>s; s = "?" + s;
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v), g[v].push_back(u);
    }
    depth[1] = 1;
    dfs_depth(1);
    dfs(1, 1);
    for(int i=1;i<=n;i++) cout << ans[i] << " "; cout << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
