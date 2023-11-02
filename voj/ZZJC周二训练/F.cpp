#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 10;
int n,m;
int ans;
int vis[N];
vector<pair<int,int>> g[N];

void dfs(int u,int sz_,int sum){
    ans = max(ans,sum);
    for(auto [v,w] : g[u]){
        if(!vis[v]){
            vis[v] = 1;
            dfs(v,sz_+1,sum+w);
            vis[v] = 0;
        }
    }
}

signed main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++) {
        vis[i] = 1;
        dfs(i,1,0);
        vis[i] = 0;
    }
    cout << ans << "\n";
    return 0;
}
