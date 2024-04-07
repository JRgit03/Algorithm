#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e3 + 10;
int n,p;
int a[N];
int dp[N][N];

void solve(){
    memset(dp, 0x3f, sizeof dp);
    cin>>n>>p; 
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        a[i] %= p;
    }
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        vector<array<int,2>> vec;
        for(int j=0;j<=p;j++){
            dp[i][j] = dp[i-1][j];
            vec.push_back({j, (j-a[i]+p)%p});
        }
        sort(vec.begin(), vec.end(), [&](auto &p, auto &q){
            return p[1] < q[1];
        });
        for(auto &[j, pre] : vec) dp[i][j] = min(dp[i][j], dp[i][pre] + 1);
    }
    cout << dp[n][p] << "\n";
}

signed main(){
    solve();
    return 0;
}
