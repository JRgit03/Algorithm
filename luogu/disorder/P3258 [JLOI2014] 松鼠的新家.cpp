#include <bits/stdc++.h>
// #define int long long
using namespace std;
const int N = 3e5 + 10;
int n;
int depth[N];
int fa[N][20]; 
vector<int> g[N];

void bfs(int root){
    memset(depth,0x3f,sizeof depth);
    depth[0] = 0; 
    depth[root] = 1;
    
    queue<int> q; q.push(root);

    while(q.size()){
        int u = q.front(); q.pop();
        for(auto &v : g[u])
            if(depth[v] > depth[u] + 1){
                depth[v] = depth[u] + 1;
                q.push(v);
                fa[v][0] = u;
                for(int k=1;k<=19;k++) 
                    fa[v][k] = fa[fa[v][k-1]][k-1];
            }
    }    
}

int lca(int a,int b){
    if(depth[a] < depth[b]) swap(a,b);
    for(int k=19;k>=0;k--)
        if(depth[fa[a][k]] >= depth[b])
            a = fa[a][k];
    if(a == b) return  a;
    for(int k=19;k>=0;k--)
        if(fa[a][k] != fa[b][k]){
            a = fa[a][k];
            b = fa[b][k];
        }
    return fa[a][0];
}

int a[N]; // path
int b[N]; // 差分数组

void dfs(int u,int f){
    for(auto &v : g[u]){
        if(v == f) continue;
        dfs(v,u);
        b[u] += b[v]; 
    }
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
    }
    bfs(1);
    for(int i=2;i<=n;i++){
        int x = a[i-1], y = a[i], p = lca(x, y);
        b[x] += 1, b[y] += 1, b[p] -= 1, b[fa[p][0]] -= 1;
    }
    dfs(1,1);
    for(int i=2;i<=n-1;i++) b[a[i]] -= 1; b[a[n]] -= 1;
    for(int i=1;i<=n;i++) cout << b[i] << "\n";
}

signed main(){
    solve();
    return 0;
}
