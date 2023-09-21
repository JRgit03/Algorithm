#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 16e3 + 10;
int n;
int ans;
int w[N];
int dp[N]; // dp[i] 表示 以 i 为 根的 最大子树和
vector<int> g[N];

void dfs(int u,int fa){
    dp[u] = w[u];

    for(auto v : g[u]){
        if(v == fa) continue;
        dfs(v,u);
        dp[u] += max(dp[v],0);
    }
    
    ans = max(ans,dp[u]);
}

int main(){
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans = *max_element(w+1,w+1+n);
    dfs(1,-1);
    cout << ans << "\n";
    return 0;
}
