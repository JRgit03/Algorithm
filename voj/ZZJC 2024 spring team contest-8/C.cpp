#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n,m,k;
vector<int> g[N];
int vis[N];
int dist1[N],dist2[N];

void bfs(int st,int dist[]){
    memset(vis, 0, sizeof vis);
    queue<int> q; 
    q.push(st);
    vis[st] = 1;
    dist[st] = 0;
    while(q.size()){
        auto u = q.front(); q.pop();
        for(auto &v : g[u]){
            if(vis[v]) continue;
            dist[v] = dist[u] + 1;
            vis[v] = 1;
            q.push(v); 
        }
    }
}

void solve(){
    cin>>n>>m>>k;
    vector<int> p(k); for(auto &x : p) cin>>x;
    while(m--){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
    }
    bfs(1,dist1);
    bfs(n,dist2);
    int sum = 0; for(auto &x : p) sum += dist2[x];
    sort(p.begin(), p.end(), [&](auto &x, auto &y){
        return (k - 1) * dist1[x] + sum - dist2[x] < (k - 1) * dist1[y] + sum - dist2[y];
    });
    int a = (k - 1) * dist1[p[0]] + sum - dist2[p[0]], b = k - 1;
    if(dist1[n] * b < a) cout << dist1[n] << "/" << "1" << "\n";
    else cout << a / gcd(a,b) << "/" << b / gcd(a,b) << "\n";
}

signed main(){
    solve();
    return 0;
}
