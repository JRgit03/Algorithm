#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 4e4 + 10;
int n,m,root;
int vis[N];
int depth[N];
int fa[N][22];
vector<int> g[N];

void bfs_lca(){
    depth[0] = 0;
    depth[root] = 1;
    vis[root] = 1;
    queue<int> q; q.push(root);

    while(q.size()){
        int u = q.front(); q.pop();

        for(auto &v : g[u]){
            if(!vis[v]){
                debug(u, v);
                vis[v] = 1;
                depth[v] = depth[u] + 1;
                q.push(v);

                fa[v][0] = u;
                for(int k=1;k<=21;k++) fa[v][k] = fa[fa[v][k-1]][k-1];
            }
        }
    }
}

int lca(int a,int b){
    if(depth[a] < depth[b]) swap(a, b);
    for(int k=21;k>=0;k--) {
        if(depth[fa[a][k]] >= depth[b]){
            a = fa[a][k];
        }
    }
    if(a == b) return a;
    for(int k=21;k>=0;k--) {
        if(fa[a][k] != fa[b][k]){
            a = fa[a][k];
            b = fa[b][k];
        }
    }
    return fa[a][0];
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b; 
        if(b == -1) root = a;
        else {
            g[a].push_back(b); g[b].push_back(a);
        }
    }
    bfs_lca();
    cin>>m;
    while(m--){
        int a,b,c; cin>>a>>b;
        c = lca(a, b); 
        if(a == c) cout << 1 << "\n";
        else if(b == c) cout << 2 << "\n";
        else cout << 0 << "\n";
    }
}

signed main(){
    IOS;
    solve();
    return 0;
}
