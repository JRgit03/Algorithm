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

int max(int a,int b){
    return a >= b ? a : b;
}

int f(int x,int y){
    return ((x % y) + y) % y; 
}

void solve(){
    int n,x,y; cin>>n>>x>>y;
    vector<int> a(n); for(auto &x : a) cin>>x;
    map<PII,int> cnt; 
    int ans = 0;
    for(int i=0;i<n;i++){
        int u = f(-a[i],x), v = f(a[i],y);
        if(cnt.count({u,v})) ans += cnt[{u,v}];
        cnt[{f(a[i],x),f(a[i],y)}] += 1;
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
