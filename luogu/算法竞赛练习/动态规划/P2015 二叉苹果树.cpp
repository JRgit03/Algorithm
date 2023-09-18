#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;
const int N = 110;
int n,q;
int sum[N]; // sum[i]表示i为根的子树的边的数量
int dp[N][N];
vector<pair<int,int>> g[N];

void dfs(int u,int fa){
    for(auto &[v,w] : g[u]){
        if(v == fa) continue;
        dfs(v,u);
        sum[u] += sum[v] + 1;
        for(int i=sum[u];i>=0;i--){ //逆序 因为 dp[u][i] 用到了 dp[u][i-j-1] 
            for(int j=0;j<i;j++){
                dp[u][i] = max(dp[u][i],dp[v][j]+dp[u][i-j-1]+w);
            }
        }
    }
}

int main(){
    IOS;
    cin>>n>>q;
    for(int i=0;i<n-1;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dfs(1,0);
    cout << dp[1][q] << "\n";
    return 0;
}
