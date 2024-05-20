#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e5 + 10;
int n,m;
int w[N]; // w[u] 经过点u的代价
int depth[N];
int dist[N];
int fa[N][21];
vector<int> g[N];

void bfs_lca(int st){
    memset(dist, 0x3f, sizeof dist);
    depth[0] = 0;
    dist[0] = 0;

    depth[st] = 1;
    dist[st] = w[st];
    queue<int> q; q.push(st);

    while(q.size()){
        int u = q.front(); q.pop();
        
        for(auto &v : g[u]){
            if(dist[v] > dist[u] + w[v]){
                dist[v] = dist[u] + w[v];
                q.push(v);

                depth[v] = depth[u] + 1;
                fa[v][0] = u;
                for(int k=1;k<=20;k++) fa[v][k] = fa[fa[v][k-1]][k-1];
            }
        }
    }

    for(int i=1;i<=n;i++) debug(depth[i]);
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
    cin>>n>>m;
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
    }
    for(int i=1;i<=n;i++) w[i] = g[i].size();
    bfs_lca(1);
    while(m--){
        int a,b; cin>>a>>b;
        if(a == b) {
            cout << w[a] << "\n";
            continue;
        }
        int c = lca(a, b); debug(a, b, c);
        int ans = dist[a] + dist[b] - dist[c] - dist[fa[c][0]];
        cout << ans << "\n";
    }
}

signed main(){
    IOS;
    solve();
    return 0;
}
