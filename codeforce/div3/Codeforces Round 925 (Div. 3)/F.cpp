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
const int N = 1e5 + 10, Mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
typedef pair<int,int> PII;
typedef long long ll;

// 假设参赛者符合 a->b->c->d->e 如果方案合法则最终一定能以某种顺序访问完所有的点 => topsort
void solve(){
    int n,k; cin>>n>>k;
    vector<int> d(n);
    vector<int> g[n];
    while(k--){
        vector<int> a(n); for(auto &x : a) cin>>x;
        for(int i=1;i<n-1;i++) {
            int u = a[i] - 1, v = a[i+1] - 1;
            g[u].push_back(v);
            d[v] += 1;
        }
    }
    auto topsort = [&](){
        queue<int> q;
        for(int i=0;i<n;i++) if(!d[i]) q.push(i);
        int m = q.size(); while(q.size()){
            int u = q.front(); q.pop();
            for(auto &v : g[u])
                if(--d[v] == 0){
                    q.push(v);
                    m += 1;
                }
        }
        return m == n;
    }; 
    cout << (topsort() ? "YES" : "NO") << "\n";
}

signed main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
