#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3 + 10, mod = 1e9 + 7;
int n,m;
string g[N];
int dp[N][N];

void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>g[i];
    dp[0][0] = 1; 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i == 0 && j == 0) || g[i][j] == '#') continue;
            if(i - 1 >= 0) dp[i][j] += dp[i-1][j];
            if(j - 1 >= 0) dp[i][j] += dp[i][j-1];
            dp[i][j] %= mod; 
        }
    }
    cout << dp[n-1][m-1] << "\n";
}

signed main(){
    solve();
    return 0;
}
