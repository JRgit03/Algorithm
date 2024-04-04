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
const int N = 1e6 + 10, mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
typedef pair<int,int> PII;
typedef long long ll;

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int n;
int x[N],y[N],c[N];

int calc(int x[]){
    for(int i=1;i<=2*n;i++) c[i] = x[i];
    sort(c+1, c+1+2*n);
    int res = 0, p = c[n];
    for(int i=1;i<=n;i++){
        int l = x[i], r = x[n+i];
        res += (abs(r - p) + abs(l - p) - abs(r - l)) / 2;
    }
    return res;
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i]>>x[n+i]>>y[n+i];
    int ans = 0;
    ans += calc(x);
    ans += calc(y);
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
