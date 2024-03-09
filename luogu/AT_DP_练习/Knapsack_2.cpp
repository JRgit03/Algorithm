// 特殊范围的01背包
// 体积价值互换 
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e2 + 10, M = 1e5 + 10, INF = 0x3f3f3f3f3f3f3f3f;
int n,m;
int w[N],v[N];
int dp[N][M];

void solve(){
    cin>>n>>m;
    int sumv = 0;
    for(int i=1;i<=n;i++) {
        cin>>w[i]>>v[i];
        sumv += v[i];
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sumv;j++){
            dp[i][j] = dp[i-1][j];
            if(j - v[i] >= 0) dp[i][j] = min(dp[i][j], dp[i-1][j-v[i]] + w[i]);
        }
    }
    int ans = 0;
    for(int j=0;j<=sumv;j++) if(dp[n][j] <= m) ans = max(ans, j); // <=m合法
    cout << ans << "\n";
}

signed main(){
    solve();
    return 0;
}

// 01背包 求前n个物品不超过m的最大价值
// N <= 100
// M <= 1000_000_000
// wi <= W
// vi <= 1000

// 转换
// => dp[i,j] 求前i个物品总价值恰好为j的最小体积










