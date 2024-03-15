#include <bits/stdc++.h>
#define int long long
using namespace std;

// 前缀和优化dp
// 题意：k颗糖分给n个人, 第i个人至少0颗,至多ai颗,必须分完,求方案数(对1e9+7取模)
// n<=100, k<=1e5, ai<=k
const int N = 1e2 + 10,M = 1e5 + 10, mod = 1e9 + 7;
int n,m;
int a[N];
int sum[M]; // sum[i] 上一层 dp[0~i]之和
int dp[N][M]; // dp[i,j] 前i个人恰好分完j个糖果的方案数
// dp[i,j] = dp[i-1,max(0, j - a[i])] + ... dp[i-1,j-1] + dp[i-1][j]

int calc(int i,int j){
    int r = j, l = max(0LL, j - a[i]);
    return sum[r] - (l-1>=0 ? sum[l-1] : 0);
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        sum[0] = dp[i-1][0];
        for(int j=1;j<=m;j++) sum[j] = (sum[j-1] + dp[i-1][j]) % mod;
        for(int j=0;j<=m;j++) {
            dp[i][j] += calc(i,j);
            dp[i][j] = (dp[i][j] % mod + mod) % mod;
        }
    }
    cout << dp[n][m] << "\n";
}

signed main(){
    solve();
    return 0;
}
