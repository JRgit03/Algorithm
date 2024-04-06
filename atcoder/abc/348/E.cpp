#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int n;
int c[N];
int sum,s[N],f[N];
int dist[N];
vector<int> g[N];

void dfs(int u,int fa){
    s[u] = c[u];
    for(auto &v : g[u]){
        if(v == fa) continue;
        dist[v] = dist[u] + 1;
        dfs(v,u);
        s[u] += s[v];
    }
}

void dfs_root(int u,int fa){
    for(auto &v : g[u]){
        if(v == fa) continue;
        f[v] = f[u] - s[v] + sum - s[v];
        dfs_root(v,u);
    }
}

void solve(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
    }
    for(int i=1;i<=n;i++) {
        cin>>c[i];
        sum += c[i];
    }
    dfs(1,1);
    for(int i=1;i<=n;i++) f[1] += c[i] * dist[i];
    dfs_root(1,1);
    int ans = LONG_LONG_MAX;
    for(int i=1;i<=n;i++) ans = min(ans, f[i]);
    // for(int i=1;i<=n;i++) cout << i << " " << f[i] << "\n";
    cout << ans << "\n";
}

signed main(){
    solve();
    return 0;
}
