#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e3 + 10;
int n,m;
string a,b;
int dp[N][N];

void solve(){
    cin>>n>>m;
    cin>>a>>b;
    a = "?" + a; b = "$" + b;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(a[i] == b[j]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        }
    cout << dp[n][m] << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
