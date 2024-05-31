#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e2 + 10, INF = 0x3f3f3f3f3f3f3f3f;
int n,m;
int dp[N][N];

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(i == j) dp[i][j] = 0;
            else dp[i][j] = INF;
        }   
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        dp[u][v] = dp[v][u] = min(dp[u][v], w);
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cout << dp[i][j] << " \n"[j == n];
}

signed main(){
    IOS;
    solve();
    return 0;
}
