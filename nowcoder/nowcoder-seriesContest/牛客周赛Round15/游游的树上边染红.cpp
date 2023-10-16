#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int n,ans;
int dp[N][2]; // dp[i,j] 以i为根的子树状态为j的最大值 j=0不选i j=1选i
vector<pair<int,int>> g[N];

void dfs(int u,int fa){
    for(auto [v,w] : g[u]){
        if(v == fa) continue;
        dfs(v,u);
        dp[u][0] += max(dp[v][0],dp[v][1]);
    }
    for(auto [v,w] : g[u]){
        if(v == fa) continue; 
        // dp[u][1] 选择u点,枚举 u - vi 两部分贡献
        // 1.选择了u-v-w => w + dp[v][0] 即 u-vi + 不选择vi的
        // 2.以u为子树除了vi子树 其他部分 => dp[u][0] - v对dp[u][0]的贡献
        // 状态更新dp[u][1] 使用到了dp[u][0] 因此必须确保 dp[u][0] 更新完毕
        dp[u][1] = max(dp[u][1],dp[u][0]-max(dp[v][0],dp[v][1]) + dp[v][0]+w);
    }
    ans = max({ans,dp[u][0],dp[u][1]});
}

signed main(){
    IOS;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dfs(1,-1);
    cout << ans << "\n";
    return 0;
}