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

void init(){
    
}

int n,m;
int x[N], s[N];

int check(int t){
    vector<array<int,2>> vec;
    for(int i=1;i<=n;i++){
        int d = t - s[i];  
        if(d < 0) continue;
        int l = max(1, x[i] - d), r = min(m, x[i] + d);
        vec.push_back({l,r});
    }
    if(vec.size() == 0) return 0;
    sort(vec.begin(), vec.end(), [&](auto& p, auto &q){
        return p[0] != q[0] ? p[0] < q[0] : p[1] < q[1];
    });
    // for(auto &v : vec) cout << v[0] << " " << v[1] << "\n";
    int l = vec[0][0], r = vec[0][1];
    for(int i=1;i<vec.size();i++){
        if(r + 1 >= vec[i][0]) r = max(r, vec[i][1]);
    }
    // cout << l << " " << r << "\n";
    return (l == 1 && r == m);
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>x[i]>>s[i];
    int l = 0, r = 1e14;
    while(l < r){
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << "\n";
    // debug(check(5));
    // debug(check(33));
}

signed main(){
    IOS;
    init();
    int T=1;
    // cin>>T;
    while(T--)
        solve();
    return 0;
}