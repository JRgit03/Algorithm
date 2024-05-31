#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 5e5 + 10;
int n,m,root;
int vis[N];
int depth[N];
int fa[N][21];
vector<int> g[N];

void bfs_lca(){
    depth[0] = 0;
    vis[root] = 1;
    depth[root] = 1;
    queue<int> q; q.push(root);
    
    while(q.size()){
        int u = q.front(); q.pop();
        
        for(auto &v : g[u]){
            if(!vis[v]){
                vis[v] = 1;
                depth[v] = depth[u] + 1;
                q.push(v);
            
                fa[v][0] = u;
                for(int k=1;k<=20;k++) fa[v][k] = fa[fa[v][k-1]][k-1];
            }
        }
    }
}

int lca(int a,int b){
    if(depth[a] < depth[b]) swap(a, b);
    for(int k=20;k>=0;k--){
        if(depth[fa[a][k]] >= depth[b]){
            a = fa[a][k];
        }
    }
    if(a == b) return a;
    for(int k=20;k>=0;k--){
        if(fa[a][k] != fa[b][k]){
            a = fa[a][k];
            b = fa[b][k];
        }
    }
    return fa[a][0];
}

void solve(){
    cin>>n>>m>>root;
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
    }
    bfs_lca();
    while(m--){
        int a,b; cin>>a>>b;
        cout << lca(a, b) << "\n";
    }
}

signed main(){
    IOS;
    solve();
    return 0;
}
