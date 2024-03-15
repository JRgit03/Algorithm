#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10, mod = 1e9 + 7;
int n;
vector<int> g[N];

// 树形dp 染色方案数
//题意：给一棵树，每一个点可以染成黑色或白色，任意两个相邻节点不能都是黑色，求方案数，结果对1e9+7取模。
// dp[u,0/1] 以u为根的子树中,将点u染为白/黑的方案数
// dp[u][0] *= (dp[v][0] + dp[v][1]) v是u的子节点
// dp[u][1] *= dp[v][0] v是u的子节点
int dp[N][2]; 

void solve(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
    }    
    function<void(int,int)> dfs = [&](int u,int f) -> void {
        dp[u][0] = dp[u][1] = 1;
        for(auto v : g[u]){
            if(v == f) continue;
            dfs(v,u);
            dp[u][0] *= (dp[v][0] + dp[v][1]);
            dp[u][0] %= mod;
            dp[u][1] *= dp[v][0];
            dp[u][1] %= mod;
        }
    }; dfs(1,1);
    cout << (dp[1][0] + dp[1][1]) % mod << "\n";
}

signed main(){
    solve();
    return 0;
}
