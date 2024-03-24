#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;
const int N = 2e5 + 10, INF = 0x3f3f3f3f3f3f3f3f;
int n,m;
int a[N],b[N];
int s[N];
int dp[N],q[N];

void solve(){
    cin>>n>>m;
    for(int i=0;i<=n;i++) {
        a[i] = b[i] = s[i] = 0;
        dp[i] = INF;
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) {
        cin>>b[i];
        s[i] += s[i-1] + b[i];
    }
    dp[n + 1] = 0;
    int l = 1, r = 0;
    q[++r] =  n+1;
    for(int i=n;i>=1;i--){
        dp[i] = dp[q[l]] + s[q[l] - 1] + a[i] - s[i];
        while(l <= r && dp[q[r]] + s[q[r] - 1] > dp[i] + s[i-1]) r -= 1;
        q[++r] = i;
    }
    int ans = INF;
    for(int i=1;i<=m;i++) ans = min(ans, dp[i]);
    cout << ans << "\n";
}

signed main(){
    IOS;
    int t; cin>>t;
    while(t--) 
        solve();
    return 0;
}
