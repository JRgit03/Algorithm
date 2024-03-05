#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define SETPRECISION cout << fixed << setprecision(10);
#define debug(x) cerr << #x << " = " << (x) << '\n'
#define debugsq(x) cerr << #x << ": ["; for (auto i : x) cerr << i << ' '; cerr << "]\n";
#define debugmp(x) cerr << #x << ": [ "; for (auto [i, j] : x) cerr << '[' << i << "," << j << "] "; cerr << "]\n";
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 10, mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
typedef pair<int,int> PII;
typedef long long ll;

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int n,m;
int tot = 0;
int dfn[N];
int siz[N];
vector<int> g[N]; 

int tr[N];
int lowbit(int x){return x&-x;}
void add(int x,int c){for(int i=x;i<=n;i+=lowbit(i)) tr[i] += c;}
int sum(int x){int res = 0;for(int i=x;i;i-=lowbit(i)) res += tr[i];return res;}

int p[N];
int ans[N];

int block,pos[N];
struct Q{
    int l,r,k,x;
    bool operator < (const Q & t) const {
        if(pos[l] != pos[t.l]) return pos[l] < pos[t.l]; 
        return r < t.r;
    }
}q[N];

void add(int x){
    add(dfn[p[x]],1);
}

void sub(int x){
    add(dfn[p[x]],-1);
}

int check(int x){
    int r = sum(dfn[x] + siz[dfn[x]] - 1);
    int l = sum(dfn[x] - 1);
    // cout << x << " " << dfn[x] << " " << dfn[x] + siz[dfn[x]] - 1 << " " <<  l << " " << r <<  "\n";
    return (r - l) > 0;
}

// 树上区间问题转为dfs序问题
// 是否存在p[l...r]的某点使得它为x的后代 <=> dfn[p[l...r]] 是否存在某点 在 dfn[x] ~ dfn[x] + siz[x] - 1(以x为根的子树中)
// 1e5 离线区间查询 莫队 + 树状数组(单点修改区间查询) n * sqrt(n) * logn  
void solve(){
    cin>>n>>m; tot = 0;
    for(int i=1;i<=n;i++) {
        ans[i] = tr[i] = dfn[i] = 0;
        g[i].clear();
    }
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
    }
    for(int i=1;i<=n;i++) cin>>p[i];
    function<void(int,int)> dfs = [&](int u,int f) -> void {
        dfn[u] = ++tot; siz[dfn[u]] = 1;
        for(auto &v : g[u]){
            if(v == f) continue;
            dfs(v,u);
            siz[dfn[u]] += siz[dfn[v]];
        }
    }; dfs(1, 1);
    block = sqrt(n);
    for(int i=1;i<=n;i++) {
        pos[i] = (i - 1) / block + 1;
    }
    for(int i=0;i<m;i++){
        cin>>q[i].l>>q[i].r>>q[i].x;
        q[i].k = i;
    }
    sort(q, q + m);
    int l = 1, r = 0;
    for(int i=0;i<m;i++){
    	// debug(l); debug(r);
    	// debug(q[i].l); debug(q[i].r);
        while(l > q[i].l) add(--l);
        while(r < q[i].r) add(++r);
        while(l < q[i].l) sub(l++);
        while(r > q[i].r) sub(r--);
        // cout << "ck: " << l << " " << " " << r << "\n";
        ans[q[i].k] = check(q[i].x);
    }
    for(int i=0;i<m;i++) 
        cout << (ans[i] ? "YES" : "NO") << "\n";
}

signed main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
