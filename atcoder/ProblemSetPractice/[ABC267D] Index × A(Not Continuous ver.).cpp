#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e3 + 10;
int n,m;
int a[N];
int dp[N][N]; // dp[i,j] A的前i个数选出B的前j个数的最大乘积之和 对于a[i] 选 or 不选

signed main(){
    memset(dp,-0x3f,sizeof dp);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j] = dp[i-1][j];
            if(j - 1 >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + j * a[i]);
        }
    }
    cout << dp[n][m] << "\n";
    return 0;
}
