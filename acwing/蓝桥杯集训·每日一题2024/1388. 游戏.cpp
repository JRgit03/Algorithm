#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e2 + 10;
int n;
int a[N];
int dp[N][N];

void solve(){
    cin>>n;
    int sum = 0;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        sum += a[i];
    }
    for(int len=1;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r = l + len - 1;
            if(l == r) dp[l][r] = a[l];
            else if(l + 1 == r) dp[l][r] = max(a[l], a[r]);
            else dp[l][r] = max(a[l] + min(dp[l+2][r], dp[l+1][r-1]), a[r] + min(dp[l+1][r-1], dp[l][r-2]));
        }
    }    
    cout << dp[1][n] << " " << sum - dp[1][n] << "\n";
}

signed main(){
    solve();
    return 0;
}
