#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e4 + 10, INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> PII;
int n;
int maxlen = -INF;
int d1[N],d2[N];
vector<PII> g[N];

void dfs(int u,int f){
    d1[u] = d2[u] = 0;
    for(auto &[v, w] : g[u]){
        if(v == f) continue;
        dfs(v, u);
        int t = d1[v] + w;
        if(t > d1[u]) d2[u] = d1[u], d1[u] = t;
        else if(t > d2[u]) d2[u] = t; 
    }
    maxlen = max(maxlen, d1[u] + d2[u]);
}

// 适用于存在负权边的树
void solve(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v, w}); g[v].push_back({u, w});
    }
    dfs(1, 1);
    cout << maxlen << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
