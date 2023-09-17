#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;
typedef long long ll;
const int N = 2e5 + 10 , INF = 1e18;
int n,m;
int x[N],y[N];
int vis[N];
vector<array<int,3>> g[N];

void dfs(int u){
    for(auto &[v,a,b] : g[u]){
        if(!vis[v]){
            vis[v] = 1;
            x[v] = x[u] + a; 
            y[v] = y[u] + b;
            dfs(v);
        }
    }
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) x[i] = y[i] = INF;
    x[1] = 0 , y[1] = 0;
    for(int i=0;i<m;i++){
        int u,v,a,b; cin>>u>>v>>a>>b;
        g[u].push_back({v,a,b});
        g[v].push_back({u,-a,-b});
    }
    vis[1] = 1; dfs(1);
    for(int i=1;i<=n;i++){
        if(x[i] == INF || y[i] == INF) cout << "undecidable" << "\n";
        else cout << x[i] << " " << y[i] << "\n"; 
    }
}

signed main(){
    IOS; solve();
    return 0;
}
