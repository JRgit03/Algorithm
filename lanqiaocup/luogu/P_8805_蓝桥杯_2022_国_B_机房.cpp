#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e5 + 10, up = 1e6, INF = 0x3f3f3f3f3f3f3f3f;
int n,m;
int w[N];
vector<int> g[N];

int dist[N];
void solve1(){
    while(m--){
        for(int i=1;i<=n;i++) dist[i] = INF;
        int a,b; cin>>a>>b;
        queue<int> q;
        q.push(a);
        dist[a] = w[a];
        
        while(q.size()){
            auto u = q.front(); q.pop();
            
            for(auto &v : g[u]){
                if(dist[v] > dist[u] + w[v]){
                    dist[v] = dist[u] + w[v];
                    q.push(v);
                }
            }
        }
        
        cout << dist[b] << "\n";
    }
}

int depth[N];
int fa[N][21];

void bfs_lca(){
    for(int i=1;i<=n;i++) dist[i] = INF;
    dist[1] = w[1];
    depth[1] = 1;
    queue<int> q; q.push(1);
    
    while(q.size()){
        auto u = q.front(); q.pop();

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

void solve2(){
    bfs_lca();
    while(m--){
        int a,b; cin>>a>>b;
        int c = lca(a, b);
        int ans = dist[a] + dist[b] - dist[c] - dist[fa[c][0]];
        cout << ans << "\n";
    }
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
    }
    for(int i=1;i<=n;i++) w[i] = g[i].size();
    if(n * m <= up && m * m <= up) solve1();
    else solve2(); 
}

signed main(){
    IOS;
    solve();
    return 0;
}
