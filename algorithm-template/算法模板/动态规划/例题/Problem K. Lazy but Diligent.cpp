/**
 * n点m条边 n<=400 edge = {u,v,w} u点到v点需要w的时间
 * 给定q个课程, 课程i = {ai,bi,pi} 表示第i个课程开始时间为ai,结束时间为bi,在pi点上
 * 上完一个课当且仅当 人在pi点且待在ai~bi的时间段里
 * 给定s, t 表示 至少要睡s单位的觉,t表示截止时间 
 * 
 * n个楼，m条路，q个课程，在t时刻必须回寝食且路上休息时间合计s时
 */
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 404, INF = 1e18;
typedef pair<int,int> PII;
int n,m,q,s,t;
int a[N],b[N],p[N]; // ai,bi,pi 第i个课程[ai,bi]在pi点上
int dist[N][N]; 
vector<PII> g[N];

int dp[N][N]; // dp[i,j] 表示上完i个课程,且以第j个课程结尾的最大休息时长

void solve(){
    memset(dp, -0x3f, sizeof dp);
    cin>>n>>m>>q>>t>>s;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w}); g[v].push_back({u,w});
        dist[u][v] = dist[v][u] = min(dist[u][v], w);
    }    
    for(int i=1;i<=q;i++) cin>>a[i]>>b[i]>>p[i];
    // floyd 预处理最短距离
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    int ans = 0;
    // dp初始化
    for(int i=1;i<=q;i++){
        if(t - b[i] - dist[p[i]][1] >= 0 && a[i] - dist[1][p[i]] >= 0){
            int sum = t - b[i] - dist[p[i]][1] + a[i] - dist[1][p[i]];
            dp[1][i] = sum;
        }
        if(dp[1][i] >= s) ans = 1;
    }
    // n^3 dp转移
    // dp[k][i] +=
    //          1. t - dist[p[i]][1] - b[i] 以p[i]为终点赶回寝室的修饰时间
    //          2. dp[k-1][j] - (t - dist[p[j]][1] - j) 减去点p[j]赶回寝室的时间
    //          3. a[i] - b[j] - dist[p[j]][1] - dist[1][p[i]] 中途是否可以回寝室睡觉
    for(int k=2;k<=q;k++){ 
        for(int i=1;i<=q;i++){ 
            int res1 = t - dist[p[i]][1] - b[i]; // 后
            if(res1 < 0) continue;
            for(int j=1;j<=q;j++){ 
                if(i != j && a[i] >= b[j] + dist[p[j]][p[i]] && dp[k-1][j] >= s){ // 从j赶到i上课
                    int res2 = dp[k-1][j] - (t - dist[p[j]][1] - j); // 前
                    int res3 = a[i] - b[j] - dist[p[j]][1] - dist[1][p[i]]; // 中
                    if(res3 < 0) res3 = 0; // 中途无休息时间
                    dp[k][i] = max(dp[k][i], res1 + res2 + res3);
                }
            }
            if(dp[k][i] >= s) ans = k;
        }
    }
    cout << ans << "\n";
}

signed main(){
    solve();
    return 0;
}


/*
Examples1:
input:
5 4 3 10 2
3 4 1
2 5 1
4 5 1
3 1 1

2 9 2
3 9 4
6 8 3

output:
1
*/

/*
Examples2:
input:
5 4 4 15 3
3 4 1
4 1 1
5 2 2
5 3 2

5 6 4
8 9 3
13 14 2
4 6 5

output:
2
*/