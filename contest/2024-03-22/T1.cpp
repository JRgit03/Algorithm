#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 10;
int n;
int a[N];
int dp[N][N];

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    function<int(int,int)> dfs = [&](int i,int j) -> int {
        if(i == j) return dp[i][j] = a[i];
        if(i + 1 == j) return dp[i][j] = max(a[i], a[j]);
        if(dp[i][j]) return dp[i][j];
        int &res = dp[i][j];
        res = max(a[i] + min(dfs(i+2,j), dfs(i+1,j-1)), a[j] + min(dfs(i+1,j-1), dfs(i,j-2)));
        return res;     
    };
    cout << dfs(1, n) << "\n";
}

signed main(){
    solve();
    return 0;
}
