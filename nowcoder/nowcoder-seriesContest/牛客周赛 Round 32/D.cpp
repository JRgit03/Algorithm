#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
string s;
int dp[N]; // dp[u] 以u为根可以到达权值为1的点的次数
vector<int> g[N];

int main(){
    cin>>n>>s; s = " " + s;
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
    }
    function<void(int,int)> dfs = [&](int u,int f) -> void {
        for(auto &v : g[u]){
            if(v == f) continue;
            dfs(v,u);
            dp[u] += dp[v] + (s[v] == '1');
        } 
    }; dfs(1,1);
    for(int i=1;i<=n;i++) cout << dp[i] << "\n";
    return 0;
}
