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
int st[N];
int dist[N];
vector<PII> g[N];

int dij(){
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    dist[1] = 0;
    heap.push({dist[1], 1});
    
    while(heap.size()){
        auto [distance, u] = heap.top(); heap.pop();
        debug(distance, u);
        if(st[u]) continue;
        st[u] = 1;
        
        for(auto [v, w] : g[u]){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                heap.push({dist[v], v});
            }
        }
    }

    return (dist[n] >= INF ? -1 : dist[n]);
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w}); // 有向图
    }
    cout << dij() << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
