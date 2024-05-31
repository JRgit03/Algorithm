#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e3 + 10;
typedef pair<int,int> PII;
int n,m;
int c[N];
int st[N];
int dist[N];
vector<PII> g[N];

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v, w}); g[v].push_back({u, w});
    }
    if(n == 1){
        cout << 0 << "\n";
        return;
    }
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    dist[1] = 0;
    heap.push({dist[1], 1});
    while(heap.size()){
        auto [distance, u] = heap.top(); heap.pop();
        if(st[u]) continue;
        st[u] = 1;
        
        for(auto &[v, w] : g[u]){
            if(dist[v] > dist[u] + w + c[v]){
                dist[v] = dist[u] + w + c[v];
                heap.push({dist[v], v});
            }
        }
    }
    cout << dist[n] - c[n] << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
