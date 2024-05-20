#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 2022 + 10;
// dp[i,j,k] 前i个数选取j个数组成体积之和为k的方案数, 第i个数的体积占i
// dp[i,j,k] = dp[i-1,j,k] 不选第i个数
// dp[i,j,k] = dp[i-1,j-1,k-i] 选第i个数
// int dp[N][11][N];
int dp[11][N];

void solve(){
    dp[0][0] = 1;
    for(int i=1;i<=2022;i++){
        for(int j=10;j>=0;j--){
            for(int k=2022;k>=0;k--){
                if(j - 1 >= 0 && k - i >= 0) {
                    dp[j][k] += dp[j-1][k-i];
                }
            }
        }
    }
    cout << dp[10][2022] << "\n"; // 379187662194355221
}

signed main(){
    IOS;
    solve();
    return 0;
}
