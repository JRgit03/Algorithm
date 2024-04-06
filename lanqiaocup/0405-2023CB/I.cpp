#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define int long long
using namespace std;

int max(int a,int b){return (a > b ? a : b); }
int min(int a,int b){return (a < b ? a : b); }

const int N = 1e5 + 10;
typedef pair<int,int> PII;
int n,k;
int a[N];
int dist[N]; 
int depth[N];
int fa[N][22];
vector<PII> g[N];

void bfs(int sx){
    queue<int> q;
    q.push(sx);
    dist[sx] = 0;
    depth[sx] = 1;
    
    while(q.size()){
        int u = q.front(); q.pop();
        
        for(auto &item : g[u]){
            int v = item.first, w = item.second;
            if(depth[v] != 0) continue;
//            cout << u << " " << v << " " << w << "\n";
            depth[v] =  depth[u] + 1;
            dist[v] = dist[u] + w;
            fa[v][0] = u;
            for(int k=1;k<=20;k++){
                fa[v][k] = fa[fa[v][k-1]][k-1];
            }
            q.push(v);
        } 
    }
}

int lca(int a,int b){
    if(depth[a] < depth[b]) swap(a, b);
    for(int k=20;k>=0;k--){
        if(depth[fa[a][k]] >= depth[b]){
            a = fa[a][k];
        }
    }
    if(a == b) return a;
    for(int k=20;k>=0;k--){
        if(fa[a][k] != fa[b][k]){
            a = fa[a][k];
            b = fa[b][k];
        }
    } 
    return fa[a][0];
}

int getdist(int x,int y){
    return dist[x] + dist[y] - 2 * dist[lca(x,y)];
}

void solve(){
    cin>>n>>k;
    for(int i=0;i<n-1;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w}); g[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++) cin>>a[i];
    bfs(1);
    int sum = 0;
    for(int i=2;i<=k;i++) sum += getdist(a[i], a[i-1]);
//    for(int i=1;i<=n;i++) cout << "dist: " << dist[i] << "\n";
//    cout << "sum: " << sum << "\n";
    for(int i=1;i<=k;i++){
        int ans = sum;
        if(i-1>=1) ans -= getdist(a[i], a[i-1]);
        if(i+1<=k) ans -= getdist(a[i], a[i+1]);
        if(i-1>=1 && i+1<=k) ans += getdist(a[i-1], a[i+1]); 
        cout << ans << " ";
    }
}

signed main(){
    IOS; solve();
    return 0;
} 

/*
6 4
1 2 1
1 3 1
3 4 2
3 5 2
4 6 3
2 6 5 1
*/

