#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define dbug(x) cout << #x << '=' << x << endl
#define debug_(x) cerr << #x << " = " << (x) << ' '
#define debug(x) cerr << #x << " = " << (x) << '\n'
#define debugsq(x) cerr << #x << ": ["; for (auto i : x) cerr << i << ' '; cerr << "]\n";
#define debugmp(x) cerr << #x << ": [ "; for (auto [i, j] : x) cerr << '[' << i << "," << j << "] "; cerr << "]\n";
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 10, Mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
typedef pair<int,int> PII;
typedef long long ll;
int n,m;
int fa[N];
int l[N],r[N],tot; // l[u] ~ r[u]表示子树u l[u]节点u的入戳 r[u]节点u的出戳
vector<int> g[N];

void dfs(int u,int f){
    l[u] = ++tot;
    fa[u] = f;
    for(auto v : g[u]){
        if(v == f) continue;
        dfs(v,u);
    }
    r[u] = ++tot;
}

// 有解 <=> fa[u] u属于给定集合 所有的fa[u]在一直线上 
void solve(){
    cin>>n>>m;
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
    }
    dfs(1,1);
    while(m--){
        int sz; cin>>sz;
        vector<int> vec(sz); for(auto &x : vec) {
            cin>>x; x = fa[x];
        }
        sort(vec.begin(),vec.end(),[&](int i,int j){return l[i] < l[j];});
        int L = 1, R = 2*n, suc = 1;
        for(int i=0;i<sz;i++){
            if(l[vec[i]] >= L && r[vec[i]] <= R){
                L = l[vec[i]]; R = r[vec[i]];
            }else suc = 0;
        }
        cout << (suc ? "YES" : "NO") << "\n";
    }
}

signed main(){
    IOS;
    int T=1;
    // cin>>T;
    while(T--)
        solve();
    return 0;
}
