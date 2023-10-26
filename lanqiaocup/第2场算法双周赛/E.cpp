#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define endl "\n"
#define dbug(x) cout << 'x = ' << x << endl
#define int long long
using namespace std;
const int N = 1e5 + 10, Mod = 1e9 + 7, INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef long long ll;
int n;
int sum;
int dist[N];
vector<PII> g[N];

void dfs(int u,int fa,int d){
    dist[u] = d;
    for(auto [v,w] : g[u]){
        if(v == fa) continue;
        dfs(v,u,d+w);
    }
}

void solve(){
    memset(dist,0x3f,sizeof dist);
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        sum += w << 1;  
    }
    // 直径一端u
    dfs(1,-1,0);
    int u = 1;
    for(int i=1;i<=n;i++) if(dist[i] > dist[u]) u = i;
    // 直径另一端v
    memset(dist,0x3f,sizeof dist);
    dfs(u,-1,0);
    int v = 1;
    for(int i=1;i<=n;i++) if(dist[i] > dist[v]) v = i;
    cout << sum - dist[v] << "\n";
}

signed main(){
    IOS; solve();
    return 0;
}
