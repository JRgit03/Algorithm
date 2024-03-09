#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int n;
int a[N],b[N],c[N];
int dp[N][3]; // dp[i,j] 表示 第i天作第j件事的最大幸福值

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<=n;i++){
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + b[i];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + c[i];
    }    
    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << "\n";
}

signed main(){
    solve();
    return 0;
}
