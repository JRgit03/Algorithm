#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 2e5 + 10, INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> PII;
int n,m;
int w[N];
int ans = INF, sum = 0;
int vis[N];
vector<int> g[N];
vector<PII> edges;

void dfs(int u,int f){
    for(auto &v : g[u]){
        if(v == f || vis[v]) continue;
        vis[v] = 1;
        sum += w[v];
        dfs(v, u);
    }
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        edges.push_back({u,v});
    }        
    if(n * m <= 100000000 && m * m <= 100000000){
        for(int i=0;i<m;i++){
            for(int j=1;j<=n;j++) {
                g[i].clear(); vis[j] = 0;
            }
            for(int j=0;j<m;j++){
                if(i == j) continue;
                auto &[u,v] = edges[j];
                g[u].push_back(v); g[v].push_back(u);
            }
            vector<int> block;
            for(int i=1;i<=n;i++) if(!vis[i]) {
                sum = w[i];
                vis[i] = 1;
                dfs(i, i);
                block.push_back(sum);
            }
            if(block.size() == 2){
                ans = min(ans, abs(block[0] - block[1]));
            }
        }
    }
    if(ans == INF) ans = -1;
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
