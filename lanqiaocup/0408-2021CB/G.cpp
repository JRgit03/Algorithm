#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b) { return (a > b ? a : b);}
int min(int a,int b) { return (a < b ? a : b);}

const int N = 1e2 + 10, M = 1e5 + 10;
int n,m;
int a[N];
int dp[N][M];

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        m += a[i];
    } 
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j] |= dp[i-1][j];
            if(j - a[i] >= 0) dp[i][j] |= dp[i-1][j - a[i]];
            if(j + a[i] <= m) dp[i][j] |= dp[i-1][j + a[i]];
            if(a[i] - j >= 0) dp[i][j] |= dp[i-1][a[i] - j];
        }
    }
    int ans = 0;
    for(int j=1;j<=m;j++) ans += dp[n][j];
    cout << ans << "\n";
}

signed main(){
    IOS; solve();
    return 0;
}

/*
3
1 4 6

10
*/
