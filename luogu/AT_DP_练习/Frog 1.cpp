#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int n;
int h[N];
int dp[N];

void solve(){
    memset(dp,0x3f,sizeof dp);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>h[i];
    dp[1] = 0;
    for(int i=2;i<=n;i++){
        if(i - 2 >= 1) dp[i] = min(dp[i], dp[i-2] + abs(h[i] - h[i-2]));
        if(i - 1 >= 1) dp[i] = min(dp[i], dp[i-1] + abs(h[i] - h[i-1]));  
    }    
    cout << dp[n] << "\n";
}

signed main(){
    solve();
    return 0;
}
