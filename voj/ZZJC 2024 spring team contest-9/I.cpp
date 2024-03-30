#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f;
int n,m;
vector<int> g[N];

int dist[N];
int bfs(int st){
    memset(dist, 0x3f, sizeof dist);
    queue<int> q;
    dist[st] = 0;
    q.push(st);
    while(q.size()){
        int u = q.front(); q.pop();
        for(auto &v : g[u]){
            if(dist[v] != INF) continue;
            dist[v] = dist[u] + 1;
            q.push(v); 
        }
    }
    int p = 1;
    for(int i=1;i<=n;i++) if(dist[i] > dist[p]) p = i;
    return p;
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
    }
    int a = bfs(1), b = bfs(a);
    int d = dist[b];
    if(d == INF) cout << -1 << "\n";
    else cout << (int)log2(d) + ((d & (-d)) != 0) << "\n";
}

signed main(){
    solve();
    return 0;
}
