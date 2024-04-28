#include <bits/stdc++.h>
#define int long long
using namespace std;

#ifdef LOCAL
#include "../../../algorithm-template/debug.h"
#else
#define debug(...) 42
#endif

const int N = 1e6 + 10, INF = 0x3f3f3f3f3f3f3f3f;
int n,m;
int x[N],y[N];
int max(int a,int b) {return a > b ? a : b;}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    int dp[n+1][m+1][2]; memset(dp, 0x3f, sizeof dp);
    dp[0][0][0] =  0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j][0] = dp[i-1][j][0];
            dp[i][j][1] = dp[i-1][j][1];
            dp[i][j][0] = min(dp[i][j][0], dp[i-1][max(0, j - x[i])][0] + y[i]);
            dp[i][j][1] = min(dp[i][j][1], dp[i-1][max(0, j - x[i])][1] + y[i]);
            dp[i][j][1] = min(dp[i][j][1], dp[i-1][max(0, j - 2 * x[i])][0] + (y[i] >> 1));            
            debug(i,j,dp[i][j][0]);
            debug(i,j,dp[i][j][1]);
        }
    }
    cout << min(dp[n][m][0], dp[n][m][1]) << "\n";
}

signed main(){
    solve();
    return 0;
}
