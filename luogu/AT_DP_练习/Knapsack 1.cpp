#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define debug(x) cerr << #x << " = " << (x) << '\n'
#define debugsq(x) cerr << #x << ": ["; for (auto i : x) cerr << i << ' '; cerr << "]\n";
#define debugmp(x) cerr << #x << ": [ "; for (auto [i, j] : x) cerr << '[' << i << "," << j << "] "; cerr << "]\n";
#define int long long
using namespace std;
const int N = 1e2 + 10, M = 1e5 + 10;
int n,m;
int w[N],v[N];
int dp[N][M]; // dp[i,j] 前i个物品体积不超过j的最大价值

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j] = dp[i-1][j];
            if(j - w[i] >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
        }
    }
    cout << dp[n][m] << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
