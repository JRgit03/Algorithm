#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 10, mod = 998244353;
int n;
int dp[N][3]; // dp[u][i] 以u为根危险点数量为i<3的合法方案数
vector<int> g[N];

void dfs(int u,int f){
    dp[u][0] = dp[u][1] = 1;
    for(auto v : g[u]){
        if(v == f) continue;
        dfs(v,u);
        dp[u][1] *= (dp[v][0] + dp[v][1]); 
        dp[u][1] %= mod;
        dp[u][2] += (dp[v][1] + dp[v][2]);
        dp[u][2] %= mod;
    }
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        dp[i][0] = dp[i][1] = dp[i][2] = 0;
        g[i].clear();
    }
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
    }
    dfs(1,1);
    cout << ((dp[1][0] + dp[1][1] + dp[1][2]) % mod + mod) % mod << "\n"; 
}

signed main(){
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

// dp[u][0] = 1 
// dp[u][1] = 1 选u为危险点
// dp[u][1] *= (dp[v][0] + dp[v][1]) 由于u可选可不选 => v可选不选 且子树互相独立
// dp[u][2] += (dp[v][1] + dp[v][2]) 子树选法是确定的, 不独立