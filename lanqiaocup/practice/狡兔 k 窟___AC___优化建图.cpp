// https://www.dotcpp.com/oj/problem3247.html
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 5e3 + 10;
int n,m;
int c[N]; // c[i] 点i的颜色为c[i]
vector<int> g[N]; // g 按照 组与组 建图

// O(n * (n + m))
// 优化建图方式
// 考虑到边权只0/1 => 01bfs
// 颜色相同的点互相之间距离为0 => 将点与点的最短路转换为<组与组>最短路
// 对于 边(u,v) => 边(c[u], c[v])

int dist[N];
int bfs(int st,int ed){
    memset(dist, 0x3f, sizeof dist);
    dist[st] = 0;
    queue<int> q;
    q.push(st);

    while(q.size()){
        int u = q.front(); q.pop();
        for(auto &v : g[u]){
            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist[ed];
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        u = c[u], v = c[v];
        g[u].push_back(v); g[v].push_back(u);
    }
    while(m--){
        int u,v; cin>>u>>v;
        u = c[u], v = c[v];
        cout << bfs(u, v) << "\n";
    }
}

signed main(){
    IOS;
    solve();
    return 0;
}


// AC 27/100 floyd暴力
// void solve(){
//     cin>>n>>m;
//     memset(dp, 0x3f, sizeof dp);
//     map<int, vector<int>> mp;
//     for(int i=1;i<=n;i++) {
//         cin>>c[i];
//         dp[i][i] = 0;
//         mp[c[i]].push_back(i);
//     }
//     for(int i=0;i<n-1;i++){
//         int u,v; cin>>u>>v;
//         dp[u][v] = dp[v][u] = min(dp[u][v], 1);
//     }
//     for(auto &[c, vec] : mp)
//         for(auto &u : vec)
//             for(auto &v : vec)
//                 dp[u][v] = dp[v][u] = 0;
//     for(int k=1;k<=n;k++)
//         for(int i=1;i<=n;i++)
//             for(int j=1;j<=n;j++)
//                 dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
//     while(m--){
//         int u,v; cin>>u>>v;
//         cout << dp[u][v] << "\n";
//     }
// }
