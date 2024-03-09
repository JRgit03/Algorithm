// N 枚硬币，第 i 枚硬币有 pi 的概率正面朝上，有 1−pi的概率反面朝上。
// 扔完所有硬币，求正面朝上的银币数比反面朝上的银币数多的概率
#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 10;
int n;
double p[N];
double dp[N][N]; // dp[i,j] 前i个银币有j个硬币朝上的概率
// dp[i,j] 枚举 硬币朝上/朝下 dp[i,j] = dp[i-1][j-1] * p[i] + dp[i-1][j] * (1- p[i])

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i];
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        dp[i][0] = dp[i-1][0] * (1 - p[i]);
        for(int j=1;j<=i;j++){
            dp[i][j] += dp[i-1][j-1] * p[i] + dp[i-1][j] * (1 - p[i]);
        }
    }
    double ans = 0.0;
    for(int i=0;i<=n;i++) 
        if(n - i < i) 
            ans += dp[n][i];
    printf("%.10lf\n", ans);
}

signed main(){
    solve();
    return 0;
}
