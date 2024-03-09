#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int n,k;
int h[N], dp[N];

void solve(){
    memset(dp, 0x3f, sizeof dp);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>h[i];
    dp[1] = 0;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=k && i - j >= 1;j++){
            dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i-j]));
        }
    }    
    cout << dp[n] << "\n";
}

signed main(){
    solve();
    return 0;
}
