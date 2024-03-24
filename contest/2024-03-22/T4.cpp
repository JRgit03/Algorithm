#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10, M = 1e4 + 10;
int n,c,k;
int t[N];
int dp[N][M];
void solve(){
    cin>>n>>c>>k;;
    for(int i=1;i<=n;i++) cin>>t[i];
    int m = min(k,n); 
    memset(dp, -1, sizeof dp);
    for(int i=0;i<=n;i++) dp[i][0] = 0;
    // dfs(i,j) 前i个作品划分为j个区间的最大作品数
    function<int(int,int,int)> dfs = [&](int i,int j,int s) -> int {
        if(dp[i][j] != -1) return dp[i][j];
        int &res = dp[i][j];
        if(i - 1 >= j) res = dfs(i-1, j, s);
        for(int k=i;k>=1;k--) 
            if(s + t[k] <= c && k - 1 >= j){
                res = max(res, 1 + dfs(k-1,j,s + t[k]));
                res = max(res, 1 + dfs(k-1,j - 1,0));
            }
        return res;
    };
    cout << dfs(n,m,0) << "\n";
}

signed main(){
    solve();
    return 0;
}
