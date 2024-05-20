/**
 * 题意：给定n块砖,第i块砖重量为wi,价值为vi,求选定k块堆叠,要求第i块砖的价值>=sum(1~i-1)的重量之和
 */
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e3 + 10, M = 2e4 + 10;
int n;

struct Node{
    int w,v;
    bool operator < (const Node& o) const {
        return w + v < o.w + o.v;
    }
}vec[N];

int dp[M]; // dp[j] 表示体积不超过j的最大价值
// dp[j] = dp[j - vec[i].w] + vec[i].v (vec[i].v >= j - vec[i].w) 

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>vec[i].w>>vec[i].v;
    sort(vec + 1, vec + 1 + n);
    for(int i=1;i<=n;i++)     
        for(int j=20000;j>=vec[i].w;j--){
            if(vec[i].v >= j - vec[i].w){
                dp[j] = max(dp[j], dp[j - vec[i].w] + vec[i].v);
            }
        }
    int ans = 0;
    for(int j=0;j<=20000;j++) ans = max(ans, dp[j]);
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
