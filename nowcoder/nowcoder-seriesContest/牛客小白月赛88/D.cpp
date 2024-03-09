#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 10;
int n,m;
int a[N];
int dp[N][2];

void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        cin>>a[i]; a[i]--;
        a[i] %= n;
    }
    dp[0][0] = 1;
    for(int i=1;i<=m;i++){
        for(int j=0;j<n;j++){
            dp[j][i & 1] |= dp[(j + a[i] + 1) % n][(i + 1) & 1];
            dp[j][i & 1] |= dp[(j - a[i] - 1 + n) % n][(i + 1) & 1];
        }
        for(int j=0;j<n;j++) dp[j][(i + 1) & 1] = 0;
    }
    cout << (dp[0][m & 1] ? "YES" : "NO") << "\n";
}

signed main(){
    solve();
    return 0;
}
