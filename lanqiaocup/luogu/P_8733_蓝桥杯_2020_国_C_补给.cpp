#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 20;
int n,d;
double dist[N][N];
// i -> j dist[i,j] 但是i,j可能经过多个点!
double dp[(1 << N) + 10][N + 10]; // dp[i,j] 经过的点集为i且终点为j的最小飞行距离 
double x[N],y[N];

double get(int i,int j){
    double dx = x[j] - x[i], dy = y[j] - y[i];
    return sqrt(dx * dx + dy * dy);
}

void solve(){
    cin>>n>>d;
    for(int i=0;i<n;i++) cin>>x[i]>>y[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = (get(i,j) <= d ? get(i,j) : 1e9);
        }
    }
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<n;j++)
            dp[i][j] = 1e9;
    dp[1][0] = 0;
    for(int i=2;i<(1<<n);i++)
        for(int j=0;j<n;j++)
            if((i >> j) & 1) 
                for(int k=0;k<n;k++)
                    if(((i ^ (1 << j)) >> k) & 1)
                        dp[i][j] = min(dp[i][j], dp[i^(1<<j)][k] + dist[k][j]);
    double ans = 1e18;
    for(int j=0;j<n;j++) ans = min(ans, dp[(1<<n)-1][j] + dist[j][0]);
    printf("%.2lf\n", ans);
}

signed main(){
    IOS;
    solve();
    return 0;
}
