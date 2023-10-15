#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const double eps = 1e-11;
int n,m;
double dp[N];
vector<tuple<int,int,int>> g[N];

// 务必从小到大枚举u 题目保证了 u < v 
// 枚举的顺序影响dp的结果
// 更新dp[v]的时候 要确保dp[u]的结果已经确定 无后效性
bool check(double x){
    for(int i=1;i<=n;i++) dp[i] = -1e9;
    dp[1] = 0;
    for(int u=1;u<=n;u++)
        for(auto [v,a,b] : g[u])
            dp[v] = max(dp[v],dp[u]+a-x*b);
    return dp[n] >= 0;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,a,b; cin>>u>>v>>a>>b; 
        g[u].push_back({v,a,b});
    }
    double l = 0 , r = 1e4;
    while(r - l > eps){
        double mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    printf("%.11lf",r);
    return 0;
}
