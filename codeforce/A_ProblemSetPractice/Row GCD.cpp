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
const int N = 2e5 + 10, mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
typedef pair<int,int> PII;
typedef long long ll;

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

void init(){
    
}

int gcd(int a,int b){
    return b ? gcd(b, a % b) : a;
}

void solve(){
    int n,m; cin>>n>>m;
    vector<int> a(n+1); for(int i=1;i<=n;i++) cin>>a[i]; 
    vector<int> b(m+1); for(int i=1;i<=m;i++) cin>>b[i];
    if(n == 1) {
        for(int i=1;i<=m;i++) cout << a[1] + b[i] << " ";
        return;
    }
    vector<int> c(n+1); for(int i=2;i<=n;i++) c[i] = abs(a[i] - a[i-1]);
    vector<int> ans(m+1);
    int x = c[2]; for(int i=3;i<=n;i++) x = gcd(x, c[i]); //debug(x); debugsq(c); 
    for(int i=1;i<=m;i++) ans[i] = gcd(a[1] + b[i], x); 
    for(int i=1;i<=m;i++) cout << ans[i] << " ";
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
