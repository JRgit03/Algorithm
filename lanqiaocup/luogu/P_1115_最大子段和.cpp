#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 2e5 + 10, INF = 0x3f3f3f3f3f3f3f3f;
int n;
int ans = -INF;
int a[N], s[N];
int dp[N];

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i]; s[i] = s[i-1] + a[i];
    }
    
    // 前缀最小值解法
    // int minn = 0; 
    // for(int i=1;i<=n;i++) {
    //     ans = max(ans, s[i] - minn);
    //     minn = min(minn, s[i]);
    // }

    // dp解法 dp[i]表示以ai结尾的最大字段和
    for(int i=1;i<=n;i++) {
        dp[i] = max(dp[i-1] + a[i], a[i]);
        ans = max(ans, dp[i]);
    }
    
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
