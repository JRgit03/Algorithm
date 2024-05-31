#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 2e3 + 10, INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> PII;
int n,m;
vector<PII> g[N];

int inq[N];
int cnt[N];
int dist[N];
int spfa(){
    dist[1] = 0;
    cnt[1] = 1;
    queue<int> q; q.push(1); inq[1] = 1;

    while(q.size()){
        int u = q.front(); q.pop(); inq[u] = 0;

        for(auto &[v, w] : g[u]){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u] + 1;
                if(cnt[v] >= n + 1) return 1;
                
                if(!inq[v]){
                    inq[v] = 1;
                    q.push(v);
                }
            }
        }
    }

    return 0;
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        g[i].clear(); cnt[i] = inq[i] = 0; dist[i] = INF; 
    }
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        if(w >= 0) g[u].push_back({v, w}), g[v].push_back({u, w});
        else g[u].push_back({v, w});
    }
    cout << (spfa() ? "YES" : "NO") << "\n";
}

signed main(){
    IOS;
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
