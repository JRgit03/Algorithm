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
int n;
int primes[N],cnt;
int st[N];

int a[N];
int dp[N];

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) a[i] += a[i-1];
    int sz = 0,ans = -INF;
    for(int i=1;i<=n;i++){
        for(int j=0;j<cnt;j++){
            if(i + primes[j] - 1 > n) break;
            sz += 1;
            ans = max(ans, a[i + primes[j] - 1] - a[i - 1]);
        }
    }
    // cout << sz << "\n"; // 504813055 => 5e8
    cout << ans << "\n";
}

signed main(){
    IOS; st[1] = 1;
    for(int i=2;i<=100000;i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j=0;primes[j]<=100000/i;j++){
            st[primes[j]*i] = 1;
            if(i % primes[j] == 0) break;
        }
    } //cout << cnt << "\n"; 9592
    int T=1;
    // cin>>T;
    while(T--)
        solve();
    return 0;
}
