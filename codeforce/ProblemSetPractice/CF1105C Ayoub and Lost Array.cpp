#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10, mod = 1e9 + 7;
int n,l,r;
int dp[N][3]; // dp[i,j] 前i个数且前i个数之和mod3为j的方案数

signed main(){
    cin>>n>>l>>r;
    dp[1][0] = r / 3 - l / 3 + (l % 3 == 0);
    dp[1][1] = (r - 1) / 3 - (l - 1) /3 + (l % 3 == 1);
    dp[1][2] = r - l + 1 - dp[1][0] - dp[1][1];
    for(int i=2;i<=n;i++){
        dp[i][0] = dp[i-1][0] * dp[1][0] % mod + dp[i-1][1] * dp[1][2] % mod + dp[i-1][2] * dp[1][1] % mod;
        dp[i][0] %= mod;
        dp[i][1] = dp[i-1][0] * dp[1][1] % mod + dp[i-1][1] * dp[1][0] % mod + dp[i-1][2] * dp[1][2] % mod;
        dp[i][1] %= mod;
        dp[i][2] = dp[i-1][0] * dp[1][2] % mod + dp[i-1][1] * dp[1][1] % mod + dp[i-1][2] * dp[1][0] % mod;
        dp[i][2] %= mod;
    }
    cout << dp[n][0] << "\n";
    return 0;
}
