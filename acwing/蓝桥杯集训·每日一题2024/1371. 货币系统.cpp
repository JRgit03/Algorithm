#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int v[55];
int dp[10010];

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i];
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(j - v[i] >= 0) dp[j] += dp[j-v[i]];
        }
    }
    cout << dp[m] << "\n";
}

signed main(){
    solve();
    return 0;
}
