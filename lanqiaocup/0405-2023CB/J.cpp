#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define int long long
using namespace std;

int max(int a,int b){return (a > b ? a : b); }
int min(int a,int b){return (a < b ? a : b); }

const int N = 1e6 + 10;
int n,m;
int depth[N];
int fa[N][22];
vector<int> g[N];

// mp = {{{u,v},id}, ....} 边 -> id
// mp2 = {{{u,v},v}, ...} 边 -> 权值点, 边权下移给节点
map<pair<int,int>,int> mp, mp2;

void bfs(int sx){
    queue<int> q;
    q.push(sx);
    depth[sx] = 1;
    
    while(q.size()){
        int u = q.front(); q.pop();

        for(auto v : g[u]){
            if(depth[v] != 0) continue;
            depth[v] = depth[u] + 1;
            mp2[{u,v}] = v;
            q.push(v);
            fa[v][0] = u;
            for(int k=1;k<=20;k++) fa[v][k] = fa[fa[v][k-1]][k-1];
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


int val[N];
void dfs(int u,int f){
    for(auto v : g[u]){
        if(v == f) continue;
        dfs(v,u);
        val[u] += val[v];
    }
    // cout << u << " " << val[u] << "\n";
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
        mp[{u,v}] = mp[{v,u}] = i+1;
    }    
    bfs(1);
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        val[a] += 1; val[b] += 1; val[lca(a,b)] -= 2;
    }
    dfs(1,1);
    int ans = -1;
    for(auto &item : mp){
        int u = item.first.first, v = item.first.second, id = item.second;
        if(mp2.count({u,v})){
            int x = mp2[{u,v}];
            if(val[x] == m && id > ans){
                ans = id;
            }
        }
    }
    cout << ans << "\n";
}

signed main(){
    IOS; solve();
    return 0;
} 

