#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 5e3 + 10, M = 2e5 + 10;
int n,m;

struct Node{
    int u,v,w;
    bool operator < (const Node& o) const {
        return w < o.w;
    }
}edges[M];

int p[N];
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void kruskal(){
    sort(edges + 1, edges + 1 + m); // m条边
    for(int i=1;i<=n;i++) p[i] = i;
    
    int cnt = 0, res = 0;
    for(int i=1;i<=m;i++){
        auto [a, b, w] = edges[i];
        int pa = find(a), pb = find(b);
        if(pa != pb){
            p[pa] = pb;
            cnt += 1;
            res += w;
        } 
    }

    if(cnt == n - 1) cout << res << "\n";
    else cout << "orz" << "\n";
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int u,v,w; cin>>u>>v>>w;
        edges[i] = {u, v, w};
    }    
    kruskal();
}

signed main(){
    IOS;
    solve();
    return 0;
}
