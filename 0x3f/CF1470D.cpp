#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define SETPRECISION cout << fixed << setprecision(10);
#define dbug(x) cout << #x << '=' << x << endl
#define debug_(x) cerr << #x << " = " << (x) << ' '
#define debug(x) cerr << #x << " = " << (x) << '\n'
#define debugsq(x) cerr << #x << ": ["; for (auto i : x) cerr << i << ' '; cerr << "]\n";
#define debugmp(x) cerr << #x << ": [ "; for (auto [i, j] : x) cerr << '[' << i << "," << j << "] "; cerr << "]\n";
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 10, Mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
typedef pair<int,int> PII;
typedef long long ll;
int n,m;
int cnt;
int col[N]; // 1 染色 0 未染色
int vis[N];
vector<int> g[N];

void dfs(int u,int f){
    int flag = 0; // 当前点的邻边上的点是否被染色
    for(auto v : g[u]) if(col[v]) flag = 1;
    col[u] = !flag; vis[u] = 1;
    for(auto v : g[u]) {
        if(v == f) continue;
        if(vis[v]) continue;
        dfs(v,u);
    }
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        vis[i] = col[i] = 0;
        g[i].clear();
    }
    while(m--){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) if(!vis[i]) {
        cout << "NO" << "\n";
        return;
    }
    cout << "YES" << "\n";
    vector<int> ans; for(int i=1;i<=n;i++) if(col[i] == 1) {
        ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++) cout << ans[i] << " \n"[i== ans.size() - 1];
}

signed main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
