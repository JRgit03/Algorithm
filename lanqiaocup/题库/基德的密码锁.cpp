#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n,m,k;
int s[5050];
int dp[1010][5010]; 

int sum(int l,int r){
    if(l > r) return 0;
    return ((s[r] - s[l-1]) % mod + mod) % mod;
}

void solve(){
    cin>>n>>m>>k;
    for(int j=1;j<=m;j++) dp[1][j] = 1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++) s[j] = (s[j - 1] % mod + dp[i - 1][j] % mod) % mod; 
        for(int j=1;j<=m;j++) {
            if(j - k != j + k) dp[i][j] = (sum(1, j - k) % mod + sum(j + k, m) % mod) % mod;
            else dp[i][j] = (sum(1, j - k - 1) % mod + sum(j + k, m) % mod) % mod;
        }
    }
    int ans = 0;
    for(int j=1;j<=m;j++) ans = (ans + dp[n][j]) % mod;
    cout << (ans % mod + mod) % mod  << "\n";
}

signed main(){
    solve();
    return 0;
}
