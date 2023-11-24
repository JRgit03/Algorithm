#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define dbug(x) cout << #x << '=' << x << endl
#define int long long
#define x first
#define y second
using namespace std;
const int N = 1e5 + 10, Mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
typedef pair<int,int> PII;
typedef long long ll;
const int maxn = 3e5 + 10;

int a[maxn];
int l[maxn],r[maxn]; //枚举点在i的l/r边的最坏情况
int f[maxn],g[maxn];

void solve(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        l[i] = a[i] + i - 1;
        r[i] = a[i] + n - i;
    }
    for(int i=1;i<=n;i++) f[i] = max(f[i-1],r[i]);
    for(int i=n;i>=1;i--) g[i] = max(g[i+1],l[i]);
    int ans = LONG_LONG_MAX;
    for(int i=1;i<=n;i++){
        ans = min(ans, max({a[i],f[i-1],g[i+1]})); 
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    int T=1;
    // cin>>T;
    while(T--)
        solve();
    return 0;
}