#include <bits/stdc++.h>
using namespace std;
int n;
int w[22][22];
int dp[1<<21][21]; //dp[i,j]从0号点开始走经过的点集为i且最后一个点为j的最短路径

int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>w[i][j];
    memset(dp,0x3f,sizeof dp); dp[1][0] = 0;
    for(int i=2;i<(1<<n);i++){
        for(int j=0;j<n;j++){ // 终点
            if(!((i >> j) & 1)) continue;
            for(int k=0;k<n;k++){ // 中转点
                if(!((i >> k) & 1)) continue;
                dp[i][j] = min(dp[i][j],dp[i-(1<<j)][k] + w[j][k]);
            }
        }
    }
    cout << dp[(1<<n)-1][n-1] << "\n";
    return 0;
}
